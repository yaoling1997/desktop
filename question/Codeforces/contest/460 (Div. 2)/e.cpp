#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
ll a,b,p,X,ans,a_inv;
ll ksm(ll a,ll b){
	ll t=1;
	while (b){
		if (b&1)t=t*a%p;
		a=a*a%p;
		b>>=1;
	}
	return t;
}
ll up(ll x,ll y){
	ll re= x/y;
	if (x>0)
		re+=x%y!=0;
	return re;
}
ll down(ll x,ll y){
	ll re= x/y;
	if (x<0)
		re-=x%y!=0;
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d%I64d%I64d",&a, &b, &p, &X);
	a_inv=ksm(a,p-2);
	ll y=b,ans=0;
	for (ll j=1;j<p;j++){
		y= y*a_inv%p;
		ll t= down(down(X-j,p-1)+y-j,p)-up(y-j,p)+1;
		t= max(t,0ll);
		ans+= t;
	}
	printf("%I64d",ans);
	return 0;
}
