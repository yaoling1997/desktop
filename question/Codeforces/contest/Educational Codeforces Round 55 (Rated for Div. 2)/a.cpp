#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5,oo=2e9+10;
int t,n,x,y,d;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d%d",&n, &x, &y, &d);
		int ans=oo;
		if ((y-x)%d==0){
			ans=abs(y-x)/d;
		}
		if ((y-1)%d==0){
			ans=min(ans,(x-1)/d+((x-1)%d!=0)+(y-1)/d);
		}
		if ((n-y)%d==0){
			ans=min(ans,(n-x)/d+((n-x)%d!=0)+(n-y)/d);
		}
		if (ans==oo)
			ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
