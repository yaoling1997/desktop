#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 1e6;
ll a[maxn];
ll sum,i,n;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+= a[i];
	}
	if (sum%2==0){
		printf("%lld\n",sum);
		return 0;
	}
	sort(a+1,a+n+1);
	for (i= 1;i<=n;i++)
		if (a[i]%2==1){
			printf("%lld\n",sum-a[i]);
			return 0;
		}
	return 0;
}
