#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define rep(i,a,n) for (int i= a;i<=n;i++)
#define ll long long
using namespace std;
const int maxn= 5e5,oo= 2e9;
ll a[maxn],f[maxn];
ll ans,Min= oo,Max;
int i,n;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%lld",&a[i]);
		Min= min(Min,a[i]);
	}
	rep(i,1,n)
		a[i]-= Min;
	ans= Min*n;
	rep(i,1,2*n){
		if (i>n) a[i]= a[i-n];
		if (a[i]){
			f[i]= f[i-1]+1;
			Max= max(Max,f[i]);
		}
	}
	ans+= Max;
	printf("%lld\n",ans);
	return 0;
}
