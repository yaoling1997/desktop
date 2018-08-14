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
ll a[maxn],b[maxn];
ll P,Q,mo=1e9+7,c=1;
ll n,m,k,a0,b0;
ll ksm(ll a,ll b){
	ll t=1;
	while (b){
		if (b&1)
			t=t*a%mo;
		b>>=1;
		a=a*a%mo;
	}
	return t;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d",&n, &m);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		a0+=!a[i];
	}
	for (int i=1;i<=n;i++){
		scanf("%I64d",&b[i]);
		b0+=!b[i];
	}
	k=a0+b0;
	Q=ksm(m,k);
	for (int i=1;i<=n;i++){
		ll A=a[i];
		ll B=b[i];
		if (A==0){
			a0--;
			if (B==0){
				b0--;
				ll cnt= m*(m-1)/2%mo;
				cnt=c*cnt%mo*ksm(m,a0+b0)%mo;
				P=(P+cnt)%mo;
				c=c*m%mo;
			}else {
				ll cnt= c*(m-B)%mo*ksm(m,a0+b0)%mo;
				P=(P+cnt)%mo;
			}
		}else {
			if (B==0){
				b0--;
				ll cnt= c*(A-1)%mo*ksm(m,a0+b0)%mo;
				P=(P+cnt)%mo;
			}else if (A<B){
				break;
			}else if (A>B){
				ll cnt=c*ksm(m,a0+b0)%mo;
				P=(P+cnt)%mo;
				break;
			}
		}
	}
	ll ans= P*ksm(Q,mo-2)%mo;
	printf("%I64d",ans);
	return 0;
}
