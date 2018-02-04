#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll int
using namespace std;
const ll maxn= 3e5,M= 17,oo= 2e9,maxm= 3e6;
vector<ll> g[maxn];
ll d[maxn],f[maxn][30],next[maxn],size[maxn],per[maxn];
ll a[maxn][2],par[maxn],C[maxn],ok[maxn],fa[maxn];
ll left[maxm],right[maxm],c[maxm],z[maxm];
ll n,m,i,j,x,y,top,L,R,o,tot,id,v,ans;
void dfs(ll o,ll depth){
	d[o]= depth;size[o]= 1;
	ll len= g[o].size(),i,p= 0;
	for (i= 0;i<len;i++){
		ll v= g[o][i];
		if (!d[v]){
			fa[v]= f[v][0]= o;
			dfs(v,depth+1);
			if (size[v]>size[p]) p= v;
			size[o]+= size[v];
		}
	}next[o]= p;
}
void dfs2(ll o){
	if (!o) return;
	a[o][0]= ++top;
	ok[top]= o;
	dfs2(next[o]);
	ll len= g[o].size(),i;
	for (i= 0;i<len;i++){
		ll v= g[o][i];
		if (v==next[o]||v==fa[o]) continue;
		dfs2(v);
	}a[o][1]= ++top;
}
void dfs3(ll o,ll fa){
	if (!o) return;
	par[o]= fa;
	dfs3(next[o],fa);
}
void update(ll o){
	ll L= z[left[o]] ? z[left[o]]:c[left[o]];
	ll R= z[right[o]] ? z[right[o]]:c[right[o]];
	c[o]= min(L,R);
}
void build(ll &o,ll l,ll r){
	if (!o) o= ++tot;
	if (l+1==r){
		if (ok[l]) c[o]= C[ok[l]];
		else c[o]= oo;
		return;
	}
	ll mid= (l+r)>>1;
	build(left[o],l,mid);
	build(right[o],mid,r);
	update(o);
}
void pushdown(ll o){
	if (z[o]){
		if (left[o]) z[left[o]]= z[o];
		if (right[o]) z[right[o]]= z[o];
		z[o]= 0;
	}
}
void change(ll o,ll l,ll r,ll L,ll R,ll v){
	if (L<=l&&r<=R){
		z[o]= v;
		return;
	}
	pushdown(o);
	ll mid= (l+r)>>1;
	if (L<mid) change(left[o],l,mid,L,R,v);
	if (mid<R) change(right[o],mid,r,L,R,v);
	update(o);
}
ll LCA(ll x,ll y){
	if (d[x]<d[y]) swap(x,y);
	ll i;
	for (i= M;i>=0;i--)
		if (d[f[x][i]]>=d[y]) x= f[x][i];
	if (x==y) return x;
	for (i= M;i>=0;i--)
		if (f[x][i]!=f[y][i])
			x= f[x][i],y= f[y][i];
	return f[x][0];
}
void modify(ll x,ll y,ll z){
	if (d[x]<d[y]) swap(x,y);
	ll lca= LCA(x,y),i;
	for (i= 1;i<=2;i++){
		while (d[x]>=d[lca]){
			if (d[par[x]]>=d[lca]){
				change(o,L,R,a[par[x]][0],a[x][0]+1,z);
				x= fa[par[x]];
			}else {
				change(o,L,R,a[lca][0],a[x][0]+1,z);
				x= fa[lca];
			}
		}
		x= y;
	}	
}
void find(ll o,ll l,ll r,ll L,ll R){
	if (L<=l&&r<=R){
		if (z[o]) ans= min(ans,z[o]);
		else ans= min(ans,c[o]);
		return;
	}
	pushdown(o);
	ll mid= (l+r)>>1;
	if (L<mid) find(left[o],l,mid,L,R);
	if (mid<R) find(right[o],mid,r,L,R);
	update(o);
}
void query(ll x){
	ans= oo;
	if (x==id) find(o,L,R,L,R);
	else {
		ll lca= LCA(id,x);
		if (lca==x){
			ll i,xx= id;
			for (i= M;i>=0;i--)
				if (d[f[xx][i]]>d[x])
					xx= f[xx][i];
			find(o,L,R,L,a[xx][0]);
			find(o,L,R,a[xx][1]+1,R);
		}else find(o,L,R,a[x][0],a[x][1]);		
	}
}
void gi(int &re){
	char c= getchar();re= 0;
	while (c<'0'||c>'9') c= getchar();
	while ('0'<=c&&c<='9') re= re*10+c-'0',c= getchar();
}
bool cmp(ll a,ll b){
	return d[a]<d[b];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	//scanf("%d%d",&n, &m);
	gi(n);gi(m);
	for (i= 1;i<n;i++){
		//scanf("%d%d",&x, &y);
		gi(x);gi(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,1);
	for (i= 1;i<=n;i++)
		per[i]= i;
	sort(per+1,per+n+1,cmp);
	dfs2(1);
	for (i= 1;i<=n;i++)
		if (!par[per[i]])
			dfs3(per[i],per[i]);
	for (i= 1;i<=M;i++)
		for (j= 1;j<=n;j++)
			f[j][i]= f[f[j][i-1]][i-1];
	L= 1;R= top+1;
	for (i= 1;i<=n;i++){
		//scanf("%d",&C[i]);
		gi(C[i]);
	}
	build(o,L,R);
	//scanf("%d",&id);
	gi(id);
	for (i= 1;i<=m;i++){
		//scanf("%d",&x);
		gi(x);
		if (x==1){
			//scanf("%d",&x);
			gi(x);
			id= x;
		}else if (x==2){
			//scanf("%d%d%d",&x, &y, &v);
			gi(x);gi(y);gi(v);
			modify(x,y,v);
		}else {
			//scanf("%d",&x);
			gi(x);
			query(x);
			printf("%d\n",ans);
		}
	}return 0;
}
