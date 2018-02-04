#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5;
ll a[maxn];
ll ans,i,n;
int main()
{
	scanf("%lld",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld",&a[i]);
		ans+= abs(a[i]-a[i-1]);
	}
	printf("%lld",ans);
	return 0;
}
