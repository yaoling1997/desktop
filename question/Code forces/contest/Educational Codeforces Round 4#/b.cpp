#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 3e5;
ll a[maxn];
ll n,i,x,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d",&n);
	for (i= 1;i<=n;i++){
		scanf("%I64d",&x);
		a[x]= i;
	}
	for (i= 2;i<=n;i++)
		ans+= abs(a[i]-a[i-1]);
	printf("%I64d",ans);
	return 0;
}
