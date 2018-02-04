#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3e5,M= 15,oo= 1e9;
vector<int> g[maxn];
char s[20];
int c[maxn],f[maxn][20],par[maxn],fa[maxn],per[maxn];
int next[maxn],d[maxn],X[maxn],Y[maxn],root[maxn];
int left[maxn],right[maxn],sum[maxn],Max[maxn],L[maxn];
int R[maxn],size[maxn];
int n,i,j,x,y,ans,top,tot,q;
void dfs(int o,int depth){
	d[o]= depth;
	size[o]= 1;
	int len= g[o].size(),i,p= 0;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!d[v]){
			f[v][0]= fa[v]= o;
			dfs(v,depth+1);
			size[o]+= size[v];
			p= size[p]>size[v]?p:v;
		}
	}next[o]= p;
}
bool cmp(int a,int b){
	return d[a]<d[b];
}
void dfs1(int o){
	if (!o) return;
	X[o]= ++tot;Y[tot]= o;
	root[o]= top;par[o]= per[i];
	dfs1(next[o]);
}
void update(int o){
	sum[o]= sum[left[o]]+sum[right[o]];
	Max[o]= max(Max[left[o]],Max[right[o]]);
}
void build(int &o,int l,int r){
	if (!o) o= ++top;
	L[o]= l,R[o]= r;
	if (l+1==r){
		sum[o]= Max[o]= c[Y[l]];
		return;
	}
	int mid= (l+r)>>1;
	build(left[o],l,mid);
	build(right[o],mid,r);
	update(o);
}
void change(int o,int v,int x){
	if (L[o]+1==R[o]){
		sum[o]= Max[o]= x;
		return;
	}
	int mid= (L[o]+R[o])>>1;
	if (v<mid) change(left[o],v,x);
	else change(right[o],v,x);
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
void askMax(int o,int l,int r,int &re){
	if (l<=L[o]&&R[o]<=r){
		re= max(re,Max[o]);
		return;
	}
	int mid= (L[o]+R[o])>>1;
	if (l<mid) askMax(left[o],l,r,re);
	if (mid<r) askMax(right[o],l,r,re);
}
void askSum(int o,int l,int r,int &re){
	if (l<=L[o]&&R[o]<=r){
		re+= sum[o];
		return;
	}
	int mid= (L[o]+R[o])>>1;
	if (l<mid) askSum(left[o],l,r,re);
	if (mid<r) askSum(right[o],l,r,re);
}
int queryMax(int x,int y){
	int a= lca(x,y),re= -oo;
	for (int i= 1;i<=2;i++){
		while (d[x]>=d[a]){
			if (d[par[x]]<=d[a]){
				askMax(root[x],X[a],X[x]+1,re);
				x= fa[a];
			}else {
				askMax(root[x],X[par[x]],X[x]+1,re);
				x= fa[par[x]];
			}
		}
		x= y;
	}return re;
}
int querySum(int x,int y){
	int a= lca(x,y),re= 0;
	for (int i= 1;i<=2;i++){
		while (d[x]>=d[a]){
			if (d[par[x]]<=d[a]){
				askSum(root[x],X[a],X[x]+1,re);
				x= fa[a];
			}else {
				askSum(root[x],X[par[x]],X[x]+1,re);
				x= fa[par[x]];
			}
		}
		x= y;
	}
	return re-c[a];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<n;i++){
		scanf("%d%d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,1);
	for (i= 1;i<=n;i++){
		scanf("%d",&c[i]);
		per[i]= i;		
	}
	sort(per+1,per+n+1,cmp);
	for (i= 1;i<=n;i++)
		if (!root[per[i]]){
			top++;x= tot+1;
			dfs1(per[i]);
			build(root[per[i]],x,tot+1);
		}
	for (i= 1;i<=M;i++)
		for (j= 1;j<=n;j++)
			f[j][i]= f[f[j][i-1]][i-1];
	scanf("%d",&q);
	for (i= 1;i<=q;i++){
		scanf("%s%d%d",s+1, &x, &y);
		if (s[2]=='H'){//change
			change(root[x],X[x],y);
			c[x]= y;
		}else if (s[2]=='M'){//qmax
			ans= queryMax(x,y);
			printf("%d\n",ans);
		}else {//qsum
			ans= querySum(x,y);
			printf("%d\n",ans);
		}
	}return 0;
}
