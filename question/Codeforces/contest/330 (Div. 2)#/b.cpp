#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 2e5,mo= 1e9+7;
ll a[maxn],b[maxn];
ll n,k,K,i,j,ans,M,p,q,x;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld%lld",&n, &k);
	K= n/k;
	M= 9;ans= 1;
	for (i= 2;i<=k;i++) M= M*10+9;
	for (i= 1;i<=K;i++) scanf("%lld",&a[i]);
	for (i= 1;i<=K;i++) scanf("%lld",&b[i]);
	for (i= 1;i<=K;i++){
		p= q= b[i];
		for (j= 2;j<=k;j++){
			p*= 10;
			q= q*10+9;
		}
		x= max(p-1,0ll)/a[i]+M/a[i]-q/a[i];
		if (b[i]!=0) x++;
		ans= ans*x%mo;
	}
	ans= (ans+mo)%mo;
	printf("%lld",ans);
	return 0;
}
