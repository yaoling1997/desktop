#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 100001,oo= 99999999;
struct node{
	int ch[4],l,r;
};
vector<int> g[maxn];
node a[maxn];
int size[maxn],c[maxn],d[maxn],zz[maxn],fa[maxn],par[maxn];
int X[maxn],Y[maxn],root[maxn],f[maxn][21],sh[maxn];
int top,tot,l,r,askmax,asksum,cha,i,j,n,q;
int dfs(int o,int s){
	d[o]= s;
	int x= 0,len= g[o].size(),p= 0,i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!d[v]){
			fa[v]= o;f[v][0]= o;
			x+= dfs(v,s+1);
		}
	}
	for (i= 0;i<len;i++)
		if (g[o][i]!=fa[o])
			if (!p || size[p]<size[g[o][i]])
				p= g[o][i];
	zz[o]= p;
	size[o]= x;
	return x+1;
}
void dfs1(int o){
	X[o]= ++tot;Y[tot]= o;root[o]= top;par[o]= sh[i];
	if (zz[o])
		dfs1(zz[o]);
}
void update(int o){
	int u= a[o].l,v= a[o].r;
	a[o].ch[0]= max(a[u].ch[0],a[v].ch[0]);
	a[o].ch[3]= a[u].ch[3]+a[v].ch[3];
}
void build(int o,int l,int r){
	a[o].ch[1]= l;a[o].ch[2]= r;
	if (r-l>1){
		int mid= (l+r)>>1;
		a[o].l= ++top;build(top,l,mid);
		a[o].r= ++top;build(top,mid,r);
		update(o);
	}else a[o].ch[0]= a[o].ch[3]= c[Y[l]];
}
void askm(int o){
	if (a[o].ch[1]>=l && a[o].ch[2]<=r){
		askmax= max(askmax,a[o].ch[0]);
		return;
	}
	int mid= (a[o].ch[1]+a[o].ch[2])>>1;
	if (l<mid) askm(a[o].l);
	if (mid<r) askm(a[o].r);
}
void asks(int o){
	if (a[o].ch[1]>=l && a[o].ch[2]<=r){
		asksum+= a[o].ch[3];
		return;
	}
	int mid= (a[o].ch[1]+a[o].ch[2])>>1;
	if (l<mid) asks(a[o].l);
	if (mid<r) asks(a[o].r);
}
void ask(int o){
	askmax= -oo;asksum= 0;
	int a1= l,a2= r,i,b1= l,b2= r;
	while (d[a1]>d[a2]){
		for (i= 20;i>0;i--)
			if (d[f[a1][i]]>=d[a2]) break;
		a1= f[a1][i];
	}
	while (d[a2]>d[a1]){
		for (i= 20;i>0;i--)
			if (d[f[a2][i]]>=d[a1]) break;
		a2= f[a2][i];
	}
	while (a1!=a2){
		for (i= 20;i>0;i--)
			if (f[a1][i]!=f[a2][i])
				break;
		a1= f[a1][i];a2= f[a2][i];
	}
	if (o==1){
		while (d[b1]>=d[a1]){
			if (d[a1]>d[par[b1]]){
				l= X[a1];r= X[b1]+1;
				askm(root[b1]);
				b1= fa[a1];
			}else {
				l= X[par[b1]];r= X[b1]+1;
				askm(root[b1]);
				b1= fa[par[b1]];
			}
		}
		while (d[b2]>=d[a2]){
			if (d[a2]>d[par[b2]]){
				l= X[a2];r= X[b2]+1;
				askm(root[b2]);
				b2= fa[a2];
			}else {
				l= X[par[b2]];r= X[b2]+1;
				askm(root[b2]);
				b2= fa[par[b2]];
			}
		}
		printf("%d\n",askmax);
	}else {
		while (d[b1]>=d[a1]){
			if (d[a1]>d[par[b1]]){
				l= X[a1];r= X[b1]+1;
				asks(root[b1]);
				b1= fa[a1];
			}else {
				l= X[par[b1]];r= X[b1]+1;
				asks(root[b1]);
				b1= fa[par[b1]];
			}
		}
		while (d[b2]>=d[a2]){
			if (d[a2]>d[par[b2]]){
				l= X[a2];r= X[b2]+1;
				asks(root[b2]);
				b2= fa[a2];
			}else {
				l= X[par[b2]];r= X[b2]+1;
				asks(root[b2]);
				b2= fa[par[b2]];
			}
		}
		int ans= asksum;asksum= 0;
		l= X[a1];r= l+1;
		asks(root[a1]);
		printf("%d\n",ans-asksum);		
	}
}
void change(int o){
	if (a[o].ch[1]>=l && a[o].ch[2]<=r){
		a[o].ch[0]= a[o].ch[3]= cha;
		return;
	}
	int mid= (a[o].ch[1]+a[o].ch[2])>>1;
	if (l<mid) change(a[o].l);
	if (mid<r) change(a[o].r);
	update(o);
}
bool cmp(int a,int b){
	return d[a]<d[b];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n-1;i++){
		int x,y;
		scanf("%d %d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (i= 1;i<=n;i++){
		scanf("%d",&c[i]);
		sh[i]= i;
	}	
	dfs(1,1);memset(par,0,sizeof(par));
	sort(sh+1,sh+n+1,cmp);
	for (i= 1;i<=n;i++)
		if (!par[sh[i]]){
			l= tot+1;top++;
			dfs1(sh[i]);
			build(top,l,tot+1);
		}
	for (i= 1;i<=20;i++)
		for (j= 1;j<=n;j++)
			f[j][i]= f[f[j][i-1]][i-1];
	scanf("%d",&q);
	for (i= 1;i<=q;i++){
		char c;
		for (j= 1;j<=5;j++)
			scanf("%c",&c);
		if (c=='X'){
			scanf("%d %d",&l, &r);
			ask(1);
		}else if (c=='M'){
			scanf("%d %d",&l, &r);
			ask(2);
		}
		else {
			for (j= 1;j<=2;j++)
				scanf("%c",&c);
			scanf("%d %d",&l, &cha);
			int gg= l;
			l= X[l];r= l+1;
			change(root[gg]);
		}
	}
	return 0;
}
