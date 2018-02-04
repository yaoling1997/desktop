#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5,M= 20,oo= 1e9;
struct edge{
	int v,w,h;
};
vector<edge> g[maxn];
char s[100];
int c[maxn],bd[maxn],d[maxn],fa[maxn],par[maxn];
int nex[maxn],per[maxn],X[maxn],Y[maxn],size[maxn];
int f[maxn][25],root[maxn];
int left[maxn],right[maxn],L[maxn],R[maxn],a[maxn];
int T,n,i,j,x,y,z,tot,top,ans;
void init(){
	memset(nex,0,sizeof(nex));
	memset(a,0,sizeof(a));
	memset(left,0,sizeof(left));
	memset(right,0,sizeof(right));
	memset(f,0,sizeof(f));
	memset(root,0,sizeof(root));
	memset(c,0,sizeof(c));
	memset(bd,0,sizeof(bd));
	memset(d,0,sizeof(d));
	memset(fa,0,sizeof(fa));
	memset(par,0,sizeof(par));
	memset(size,0,sizeof(size));
	int i;
	for (i= 0;i<=n;i++)
		g[i].clear();
	tot= top= 0;
}
void prepare(int o,int depth){
	d[o]= depth;
	size[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i].v,h= g[o][i].h;
		if (v==fa[o]) continue;
		fa[v]= o;
		f[v][0]= o;
		c[v]= g[o][i].w;
		bd[h]= v;
		prepare(v,depth+1);
		size[o]+= size[v];
		if (size[v]>size[nex[o]])
			nex[o]= v;
	}
}
void dfs(int o){
	if (!o) return;
	root[o]= top;
	par[o]= per[i];
	X[o]= ++tot;
	Y[tot]= o;
	dfs(nex[o]);
}
void update(int o){
	a[o]= max(a[left[o]],a[right[o]]);
}
void build(int &o,int l,int r){
	if (!o) o= ++top;
	L[o]= l;R[o]= r;
	if (l+1==r){
		a[o]= c[Y[l]];
		return;
	}
	int m= (l+r)>>1;
	build(left[o],l,m);
	build(right[o],m,r);
	update(o);
}
int lca(int x,int y){
	if (d[x]<d[y]) swap(x,y);
	int i;
	for (i= M;i>=0;i--)
		if (d[f[x][i]]>=d[y])
			x= f[x][i];
	if (x==y) return x;
	for (i= M;i>=0;i--)
		if (f[x][i]!=f[y][i])
			x= f[x][i],y= f[y][i];
	return f[x][0];
}
bool cmp(int a,int b){
	return d[a]<d[b];
}
void change(int o,int v,int x){
	if (L[o]+1==R[o]){
		a[o]= x;
		return;
	}
	int m= (L[o]+R[o])>>1;
	if (v<m) change(left[o],v,x);
	else change(right[o],v,x);
	update(o);
}
void find(int o,int l,int r,int &re){
	if (l<=L[o]&&R[o]<=r){
		re= max(re,a[o]);
		return;
	}
	int m= (L[o]+R[o])>>1;
	if (l<m) find(left[o],l,r,re);
	if (m<r) find(right[o],l,r,re);
}
int ask(int x,int y){
	int a= lca(x,y),re= -oo,i;
	for (i= 1;i<=2;i++){
		while (d[x]>d[a]){
			if (d[par[x]]>d[a])
				find(root[x],X[par[x]],X[x]+1,re);
			else 
				find(root[x],X[a]+1,X[x]+1,re);			
			x= fa[par[x]];			
		}
		x= y;
	}return re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		scanf("%d",&n);
		init();
		for (i= 1;i<n;i++){
			scanf("%d%d%d",&x, &y, &z);
			g[x].push_back((edge){y,z,i});
			g[y].push_back((edge){x,z,i});			
		}
		prepare(1,1);
		for (i= 1;i<=n;i++)
			per[i]= i;
		sort(per+1,per+n+1,cmp);
		for (i= 1;i<=n;i++)
			if (!root[per[i]]){
				top++;
				x= tot+1;
				dfs(per[i]);
				build(root[per[i]],x,tot+1);
			}
		for (i= 1;i<=M;i++)
			for (j= 1;j<=n;j++)
				f[j][i]= f[f[j][i-1]][i-1];
		while (scanf("%s",s+1)>0){
			if (s[1]=='D') break;
			scanf("%d%d",&x, &y);
			if (s[1]=='C'){
				change(root[bd[x]],X[bd[x]],y);
				c[bd[x]]= y;
			}else {//Q
				ans= ask(x,y);
				printf("%d\n",ans);
			}
		}
	}return 0;
}
