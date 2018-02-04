#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 5e5;
char s[maxn];
ll a[maxn];
ll n,i,j,ans;
int  main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s",s+1);
	n= strlen(s+1);
	for (i= 1;i<=n;i++){
		a[i]= s[i]-'0';
		if (a[i]%4==0) ans++;
	}
	for (i= 2;i<=n;i++)
		if ((a[i-1]*10+a[i])%4==0)
			ans+= i-1;
	printf("%lld",ans);
}
