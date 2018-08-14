#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 3e3;
ll i,n,x,y,ans,now;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld",&x);
		now|= x;
	}
	ans= now;
	now= 0;
	for (i= 1;i<=n;i++){
		scanf("%lld",&x);
		now|= x;
	}
	ans+= now;
	printf("%lld",ans);
}
