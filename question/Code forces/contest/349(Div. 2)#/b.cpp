#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 2e5;
ll i,n,x,sum,Max;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d",&n);
	for (i= 1;i<=n;i++){
		scanf("%I64d",&x);
		Max= max(Max,x);
		sum+= x;
	}
	sum-= Max;
	printf("%I64d",Max-sum+1);
	return 0;
}