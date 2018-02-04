#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll maxl= 3e5,maxn= 2e6,oo= 1e15;
struct edge{
	ll to,w;
};
vector<edge> g[maxl];
ll a[maxn],b[maxn],c[maxn],w[maxn],H[maxl];
ll stack[maxl],vis[maxl],d[maxl],ok[maxl],G[maxl],C[maxl];
ll x,y,z,i,j,n,top,bl,B,A,ans,now,sum,L,R,sh;
void dfs(ll o,ll fa){
	vis[o]= 1;
	ll len= g[o].size(),i;
	for (i= 0;i<len;i++){
		edge e= g[o][i];
		if (e.to==fa) continue;
		if (!vis[e.to]){
			dfs(e.to,o);
			if (bl){
				if (B){
					stack[++top]= o;
					d[top]= e.w;
					ok[o]= 1;
					if (B==o) B= 0;
				}return;
			}
		}else if (vis[e.to]){
			bl= 1;B= e.to;
			stack[++top]= o;
			d[top]= e.w;
			ok[o]= 1;
			return;
		}
	}
}
void go(ll o,ll fa){
	ll len= g[o].size(),i,x= 0,y= 0;
	for (i= 0;i<len;i++){
		edge e= g[o][i];
		if (e.to==fa) continue;
		go(e.to,o);
		if (G[e.to]+e.w>x)
			y= x,x= G[e.to]+e.w;
		else if (G[e.to]+e.w>y)
			y= G[e.to]+e.w;
	}G[o]= x;A= max(A,x+y);
}
void update(ll o,ll l,ll r){
	a[o]= max(a[2*o]+c[2*o],a[2*o+1]+c[2*o+1]);
	b[o]= max(b[2*o]-c[2*o],b[2*o+1]-c[2*o+1]);
	w[o]= max(w[2*o],w[2*o+1]);
	w[o]= max(w[o],a[2*o+1]+c[2*o+1]+b[2*o]-c[2*o]);
}
void build(ll o,ll l,ll r){
	if (l+1<r){
		ll mid= (l+r)>>1;
		build(2*o,l,mid);
		build(2*o+1,mid,r);
		update(o,l,r);
	}else a[o]= C[l]+H[l],b[o]= -C[l]+H[l];
}
void pushdown(ll o){
	c[2*o]+= c[o];
	c[2*o+1]+= c[o];
	c[o]= 0;
}
void change(ll o,ll l,ll r,ll x,ll y,ll v){
	if (x<=l&&r<=y){
		c[o]+= v;
		return;
	}pushdown(o);
	ll mid= (l+r)>>1;
	if (x<mid) change(2*o,l,mid,x,y,v);
	if (mid<y) change(2*o+1,mid,r,x,y,v);
	update(o,l,r);
}
void modify(ll o,ll l,ll r,ll x){
	if (l+1<r){
		ll mid= (l+r)>>1;
		if (x<mid)	modify(2*o,l,mid,x);
		else modify(2*o+1,mid,r,x);
		update(o,l,r);
	}else a[o]= C[l]+G[stack[l]],b[o]= -C[l]+G[stack[l]];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld %lld %lld",&x, &y, &z);
		g[x].push_back((edge){y,z});
		g[y].push_back((edge){x,z});
	}
	dfs(1,0);
	for (i= 1;i<=top;i++){
		ll u= stack[i],len= g[u].size();
		x= 0;y= 0;
		for (j= 0;j<len;j++){
			edge e= g[u][j];
			if (!ok[e.to]){
				go(e.to,u);
				if (G[e.to]+e.w>x)
					y= x,x= G[e.to]+e.w;
				else if (G[e.to]+e.w>y)
					y= G[e.to]+e.w;
			}
		}H[i]= G[u]= x;A= max(A,x+y);
	}
	for (i= 2;i<=top;i++)
		C[i]+= C[i-1]+d[i];
	for (i= top+1;i<=2*top;i++)
		stack[i]= stack[i-top];
	sum= C[top]+d[1];
	L= 1;R= 2*top+1;
	ans= oo;
	build(1,1,R);
	for (i= 2;i<=top;i++){
		ans= min(ans,w[1]);
		change(1,L,R,i,top+i-1,-d[i]);
		C[top+i-1]= sum-d[i];H[top+i-1]= H[i-1];
		modify(1,L,R,top+i-1);
		G[stack[i-1]]= -oo;
		modify(1,L,R,i-1);
	}ans= min(ans,w[1]);
	ans= max(ans,A);
	printf("%.1lf",ans/2.0);
	return 0;
}
