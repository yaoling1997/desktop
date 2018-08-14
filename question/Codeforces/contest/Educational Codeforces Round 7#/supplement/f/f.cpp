#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll mo= 1e9+7,maxn= 2e6;
ll p[maxn];
ll u,d,cnt;
ll n,k,i,j,M;
ll ksm(ll a,ll b){
	ll t= 1;
	while (b){
		if (b&1) t= a*t%mo;
		b>>= 1;a= a*a%mo;
	}return t;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld%lld",&n, &k);
	M= k+2;
	for (i= 1;i<=k+1;i++)
		p[i]= (p[i-1]+ksm(i,k))%mo;
	if (n<=k+1) printf("%lld\n",p[n]);
	else {
		i= 1;
		u= d= 1;
		for (j= 2;j<=M;j++){
			u= u*(n-j+1)%mo;
			d= d*(1-j)%mo;
		}
		u= (u+mo)%mo;
		d= (d+mo)%mo;
		cnt= (cnt+u*ksm(d,mo-2)%mo*p[i-1])%mo;
		u= u*(n-i+1)%mo*ksm(n-i,mo-2)%mo;
		d= d*i%mo*ksm(i-M+mo,mo-2)%mo;
		for (i= 2;i<=M;i++){
			u= (u+mo)%mo;
			d= (d+mo)%mo;
			cnt= (cnt+(u*ksm(d,mo-2))%mo*p[i-1])%mo;
			u= u*(n-i+1)%mo*ksm(n-i,mo-2)%mo;
			d= d*i%mo*ksm(i-M+mo,mo-2)%mo;			
		}
		printf("%lld",cnt);
	}return 0;
}
