#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 100;
ll a[maxn];
ll n,i,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ans= a[n];
	for (i= n-1;i>0;i--){
		a[i]= min(a[i],a[i+1]-1);
		if (a[i]<=0) break;
		ans+= a[i];
	}
	printf("%lld",ans);
}
