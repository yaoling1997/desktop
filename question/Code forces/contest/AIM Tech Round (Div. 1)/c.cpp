#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 2e5,oo= 1e18;
struct point{
	ll x,y;
}p[maxn];
ll ypa[maxn],ypi[maxn],ysa[maxn],ysi[maxn];
ll ans;
ll n,i,j,k,xmax,xmin,ymax,ymin,l,r;
bool cmp(point a,point b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
ll D2(ll x){
	return x*x;
}
ll D2(ll x,ll y){
	return x*x+y*y;
}
bool ok(ll M){
	ll i,j= 1;
	for (i= 1;i<=n;i++){
		if (p[i].x>0) break;
		while (j+1<=n&&abs(p[j+1].x)<=-p[i].x&&D2(p[j+1].x-p[i].x)<=M) j++;
		while (abs(p[j].x)>-p[i].x) j--;
		ll ymax= max(ypa[i-1],ysa[j+1]);
		ll ymin= min(ypi[i-1],ysi[j+1]);
		if (ymax<ymin) return 1;
		if (D2(ymax-ymin)<=M&&D2(ymax,p[i].x)<=M&&D2(ymin,p[i].x)<=M)
			return 1;
	}return 0;	
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	xmin= ymin= oo;
	xmax= ymax= -oo;
	for (i= 1;i<=n;i++){
		scanf("%lld%lld",&p[i].x, &p[i].y);
		xmax= max(xmax,p[i].x);
		xmin= min(xmin,p[i].x);
		ymax= max(ymax,p[i].y);
		ymin= min(ymin,p[i].y);
	}
	ans= min(xmax-xmin,ymax-ymin);
	ans= ans*ans;
	sort(p+1,p+n+1,cmp);
	ypa[0]= ysa[n+1]= -oo;
	ypi[0]= ysi[n+1]= oo;
	for (i= 1;i<=n;i++){
		j= n-i+1;
		ypa[i]= max(ypa[i-1],p[i].y);
		ypi[i]= min(ypi[i-1],p[i].y);
		ysa[j]= max(ysa[j+1],p[j].y);
		ysi[j]= min(ysi[j+1],p[j].y);
	}
	for (ll I= 1;I<=2;I++){
		l= -1,r= oo;		
		while (l+1<r){
			ll mid= (l+r)>>1;
			if (ok(mid)) r= mid;
			else l= mid;
		}
		ans= min(ans,r);		
		for (i= 1;i<=n;i++)	p[i].x*= -1;
		sort(p+1,p+n+1,cmp);
		for (i= 1;i<=n;i++){
			j= n-i+1;
			ypa[i]= max(ypa[i-1],p[i].y);
			ypi[i]= min(ypi[i-1],p[i].y);
			ysa[j]= max(ysa[j+1],p[j].y);
			ysi[j]= min(ysi[j+1],p[j].y);
		}		
	}
	printf("%lld\n",ans);
	return 0;
}
