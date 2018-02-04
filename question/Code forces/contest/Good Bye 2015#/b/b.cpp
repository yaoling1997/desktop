#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 1e5,oo= 2e18;
ll d[maxn],s[maxn],sta[maxn];
ll a,b,i,j,ans,la,p,Max;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	d[0]= s[0]= 1;
	for (i= 1;i<=100;i++){
		d[i]= d[i-1]*2;
		s[i]= d[i]+s[i-1];
		Max= i;
		if (s[i]>oo) break;
	}
	for (i= 1;i<=Max;i++)
		for (j= 0;j<i;j++)
			sta[++la]= s[i]^((ll)1<<j);
	scanf("%lld%lld",&a, &b);
	for (i= 1;i<=la;i++)
		if (a<=sta[i]&&sta[i]<=b) ans++;
	printf("%lld\n",ans);
	return 0;
}
