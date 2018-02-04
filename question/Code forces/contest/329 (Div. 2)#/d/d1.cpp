#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const ll oo = 2*1e18;
const ll maxn= 4e5+10,maxm= 5e6,M= 17;
struct edge{
	int v,h;
};
vector<edge> g[maxn];
ll c[maxn],Max[maxm];
int f[maxn][20];
int par[maxn],fa[maxn],per[maxn];
int nex[maxn],d[maxn],X[maxn],Y[maxn],root[maxn];
int left[maxm],right[maxm],L[maxn];
int R[maxn],size[maxn];
int bd[maxn],db[maxn];
ll s,x,y,ans;
ll n,m,i,j,top,tot;
void dfs(ll o,ll depth){
	d[o]= depth;
	size[o]= 1;
	ll len= g[o].size(),i,p= 0;
	for (i= 0;i<len;i++){
		ll v= g[o][i].v;
		if (!d[v]){
			f[v][0]= fa[v]= o;
			bd[g[o][i].h]= v;
			db[v]= g[o][i].h;
			dfs(v,depth+1);
			size[o]+= size[v];
			p= size[p]>size[v]?p:v;
		}
	}nex[o]= p;
}
bool cmp(ll a,ll b){
	return d[a]<d[b];
}
void dfs1(ll o){
	if (!o) return;
	X[o]= ++tot;Y[tot]= o;
	root[o]= top;par[o]= per[i];
	dfs1(nex[o]);
}
void update(ll o){
	ld x= (ld)Max[left[o]]*Max[right[o]];
	if (x>oo) Max[o]= oo;
	else Max[o]= Max[left[o]]*Max[right[o]];
}
void build(int &o,ll l,ll r){
	if (!o) o= ++top;
	L[o]= l,R[o]= r;
	if (l+1==r){
		Max[o]= c[db[Y[l]]];
		return;
	}
	ll mid= (l+r)>>1;
	build(left[o],l,mid);
	build(right[o],mid,r);
	update(o);
}
void change(ll o,ll v,ll x){
	if (L[o]+1==R[o]){
		Max[o]= x;
		return;
	}
	ll mid= (L[o]+R[o])>>1;
	if (v<mid) change(left[o],v,x);
	else change(right[o],v,x);
	update(o);
}
ll lca(ll x,ll y){
	if (d[x]<d[y]) swap(x,y);
	ll i;
	for (i= M;i>=0;i--)
		if (d[f[x][i]]>=d[y])
			x= f[x][i];
	if (x==y) return x;
	for (i= M;i>=0;i--)
		if (f[x][i]!=f[y][i])
			x= f[x][i],y= f[y][i];
	return f[x][0];
}
void askMax(ll o,ll l,ll r,ll &re){
	if (l<=L[o]&&R[o]<=r){
		re/= Max[o];
		return;
	}
	ll mid= (L[o]+R[o])>>1;
	if (l<mid) askMax(left[o],l,r,re);
	if (mid<r) askMax(right[o],l,r,re);
}
ll queryMax(ll x,ll y,ll s){
	ll a= lca(x,y);
	for (ll i= 1;i<=2;i++){
		while (d[x]>d[a]){
			if (d[par[x]]<=d[a]){
				askMax(root[x],X[nex[a]],X[x]+1,s);
				x= fa[a];
			}else {
				askMax(root[x],X[par[x]],X[x]+1,s);
				x= fa[par[x]];
			}
		}
		x= y;
	}return s;
}
int main()
{
	scanf("%I64d%I64d",&n, &m);
	c[0]= 1;
	for (i= 1;i<n;i++){
		scanf("%I64d%I64d%I64d",&x, &y, &c[i]);
		g[x].push_back((edge){(int)y,i});
		g[y].push_back((edge){(int)x,i});
	}
	dfs(1,1);
	for (i= 1;i<=n;i++)
		per[i]= i;			
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
	for (i= 1;i<=m;i++){
		scanf("%I64d%I64d%I64d",&s, &x, &y);
		if (s==2){
			change(root[bd[x]],X[bd[x]],y);
			c[x]= y;
		}else {
			scanf("%I64d",&s);
			ans= queryMax(x,y,s);
			printf("%I64d\n",ans);
		}
	}return 0;
}
