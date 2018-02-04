#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
const ll maxn= 2e5;
ll a[maxn],b[maxn];
ll sum,n,i,x,ans,M,mo;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%I64d",&n);
	for (i= 1;i<=n;i++){
		scanf("%I64d",&a[i]);
		sum+= a[i];
	}
	M= sum/n;
	for (i= 1;i<=n;i++)
		b[i]= M;
	mo= sum%n;
	for (i= n;i>=n-mo+1;i--)
		b[i]++;
	sort(a+1,a+n+1);
	for (i= 1;i<=n;i++)
		ans+= max(b[i]-a[i],0ll);
	printf("%I64d\n",ans);
	return 0;
}
