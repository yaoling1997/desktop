#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
const ll maxn= 2e5;
ll a[maxn],c[maxn];
double x;
ll n,i,sum,m,ans,p,cnt;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld",&c[i]);
		sum+= c[i];
	}m= sum/n;
	for (i= 2;i<=n;i++){
		cnt+= c[i-1];
		a[i]= cnt-(i-1)*m;
	}
	sort(a+1,a+n+1);
	p= a[(n+1)/2];
	if ((n&1)==0){
		x= (a[n/2]+a[n/2+1])/2;
		if (x-a[n/2]>a[n/2+1]-x) p= a[n/2+1];
	}
	for (i= 1;i<=n;i++)
		ans+= abs(a[i]-p);
	printf("%lld\n",ans);
	return 0;
}
