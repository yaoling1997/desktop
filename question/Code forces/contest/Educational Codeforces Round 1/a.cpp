#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
ll t,n,i,x,ans;
int main()
{
	scanf("%lld",&t);
	while (t--){
		scanf("%lld",&n);
		ans= n*(n+1)/2;
		x= 1;
		while (x<=n){
			ans-= 2*x;
			x<<= 1;
		}
		printf("%lld\n",ans);
	}return 0;
}
