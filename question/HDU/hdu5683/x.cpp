#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 3e4,maxm= 2e6,M= 31,oo= 1e18;
struct query{
	ll x,y;
}Q[maxn];
ll d[50],a[maxm],left[maxm],right[maxm];
ll ans[maxn][50],c[maxn],o[maxn];
ll T,n,m,i,j,x,y,z,u,top,root;
void init(){
	memset(ans,0,sizeof(ans));	
	ll i;
	for (i= 1;i<=top;i++)
		a[i]= left[i]= right[i]= 0;
	top= 0;
}
void update(ll o){
	a[o]= a[left[o]]+a[right[o]];
}
void find(ll o,ll l,ll r,ll x,ll y,ll &re){
	if (!o) return;
	if (x<=l&&r<=y){
		re+= a[o];
		return;
	}
	ll m= (l+r)>>1;
	if (x<m) find(left[o],l,m,x,y,re);
	if (m<y) find(right[o],m,r,x,y,re);
}
ll find(ll x,ll i){
	ll re= 0;
	find(root,0,d[i],d[i-1]-x,d[i]-x,re);
	find(root,0,d[i],d[i]+d[i-1]-x,oo,re);
	return re;
}
void insert(ll &o,ll l,ll r,ll v){
	if (!o) o= ++top;
	if (l+1==r){
		a[o]++;
		return;
	}
	ll m= (l+r)>>1;
	if (v<m) insert(left[o],l,m,v);
	else insert(right[o],m,r,v);
	update(o);
}
void remove(ll &o,ll l,ll r,ll v){
	if (!o) return;
	if (l+1==r){
		a[o]--;
		return;
	}
	ll m= (l+r)>>1;
	if (v<m) remove(left[o],l,m,v);
	else remove(right[o],m,r,v);
	update(o);
}
void clearTree(){
	int i;
	for (i= 1;i<=top;i++)
		left[i]= right[i]= a[i]= 0;
	top= 0;
	root= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	d[0]= 1;
	for (i= 1;i<=35;i++)
		d[i]= d[i-1]*2;
	scanf("%I64d",&T);
	for (ll tt= 1;tt<=T;tt++){
		scanf("%I64d%I64d",&n, &m);
		init();
		for (i= 1;i<=n;i++)
			scanf("%I64d",&o[i]);
		for (ll mm= 1;mm<=m;mm++){
			scanf("%I64d%I64d",&y, &z);
			Q[mm]= (query){y,z};
		}
		for (j= 1;j<=M;j++){			
			clearTree();
			for (i= 1;i<=n;i++){
				c[i]= o[i];			
				x= c[i]%d[j];
				ans[0][j-1]+= find(x,j);
				insert(root,0,d[j],x);
			}
			for (ll mm= 1;mm<=m;mm++){
				y= Q[mm].x;
				z= Q[mm].y;
				x= c[y]%d[j];
				remove(root,0,d[j],x);				
				ans[mm][j-1]= ans[mm-1][j-1]-find(x,j);
				c[y]= z;
				x= c[y]%d[j];
				ans[mm][j-1]+= find(x,j);
				insert(root,0,d[j],x);
			}
		}
		for (i= 1;i<=n;i++){
			x= 0;
			for (j= 0;j<M;j++)
				x+= d[j]*(ans[i][j]&1);
			printf("%I64d\n",x);
		}
	}
	return 0;
}
