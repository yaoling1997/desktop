#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll maxn= 5e5,maxm= 3e6,mo= 1e9+7;
struct query{
	ll x,y,z;
}Q[maxn];
vector<int> g[maxn];
ll v[maxn],X[maxn],Y[maxn],a[maxn][4];
ll S[maxm],M[maxm],d[maxn];
ll left[maxm],right[maxm];
ll ans,m;
ll i,j,q,n,N,tot,top,x,y,z,root,L,R;
void gcd(ll a,ll b,ll &x,ll &y){
	if (!b){
		x= 1;
		y= 0;
		return;
	}
	gcd(b,a%b,x,y);
	ll t= x;
	x= y;
	y= t-a/b*y;
}
void dfs(ll o,ll fa){
	a[o][0]= ++tot;
	ll len= g[o].size(),i;
	for (i= 0;i<len;i++){
		ll v= g[o][i];
		if (v==fa) continue;
		dfs(v,o);
	}
	a[o][1]= ++tot;
}
void build(ll &o,ll l,ll r){
	if (!o) o= ++top;
	M[o]= 1;
	if (l+1==r){
		return;
	}
	ll mid= (l+r)>>1;
	build(left[o],l,mid);
	build(right[o],mid,r);
}
void pushdown(ll o){
	ll l= left[o],r= right[o];
	M[l]= M[l]*M[o]%mo;
	M[r]= M[r]*M[o]%mo;
	M[o]= 1;
}
void update(ll o){
	ll l= left[o],r= right[o];
	S[o]= (S[l]*M[l]%mo+S[r]*M[r]%mo)%mo;
}
void change(ll o,ll l,ll r,ll x,ll v){
	if (l+1==r){
		S[o]= v;
		return;
	}
	pushdown(o);
	ll mid= (l+r)>>1;
	if (x<mid) change(left[o],l,mid,x,v);
	else change(right[o],mid,r,x,v);
	update(o);
}
void modify(ll o,ll l,ll r,ll x,ll y,ll z){
	if (x<=l&&r<=y){
		M[o]= M[o]*z%mo;
		return;
	}
	pushdown(o);
	ll mid= (l+r)>>1;
	if (x<mid) modify(left[o],l,mid,x,y,z);
	if (mid<y) modify(right[o],mid,r,x,y,z);
	update(o);
}
void getS(ll o,ll l,ll r,ll x,ll y){
	if (x<=l&&r<=y){
		ans= (ans+S[o]*M[o]%mo)%mo;
		return;
	}
	pushdown(o);
	ll mid= (l+r)>>1;
	if (x<mid) getS(left[o],l,mid,x,y);
	if (mid<y) getS(right[o],mid,r,x,y);
	update(o);
}
void getM(ll o,ll l,ll r,ll x){
	if (l+1==r){
		m= M[o]%mo;
		return;
	}
	pushdown(o);
	ll mid= (l+r)>>1;
	if (x<mid) getM(left[o],l,mid,x);
	else getM(right[o],mid,r,x);
	update(o);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d%I64d",&v[1], &q);
	n= 1;
	for (i= 1;i<=q;i++){
		z= 0;
		scanf("%I64d%I64d",&x, &y);
		if (x==1){
			scanf("%I64d",&z);
			n++;
			g[y].push_back(n);
			g[n].push_back(y);
		}
		Q[i]= (query){x,y,z};		
	}
	d[1]= 1;
	dfs(1,0);
	L= 1,R= tot+1;
	build(root,L,R);
	change(root,L,R,a[1][0],v[1]);
	N= 1;
	for (i= 1;i<=q;i++){
		x= Q[i].x;
		y= Q[i].y;
		z= Q[i].z;
		if (x==1){
			N++;
			ll xx,yy;
			gcd(d[y],mo,xx,yy);
			d[y]++;
			xx= xx*d[y]%mo;
			modify(root,L,R,a[y][0],a[y][1]+1,xx);
			v[N]= z;
			change(root,L,R,a[N][0],v[N]);
			d[N]= 1;
		}else {
			ans= 0;
			getS(root,L,R,a[y][0],a[y][1]+1);
			getM(root,L,R,a[y][0]);
			ll xx,yy;
			m= (m+mo)%mo;
			gcd(m,mo,xx,yy);
			ans= ans*xx%mo*d[y]%mo;
			ans= (ans+mo)%mo;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}
