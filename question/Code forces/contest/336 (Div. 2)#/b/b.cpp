#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 3e5;
char a[maxn],b[maxn];
ll s[maxn];
ll n,m,k,i,j,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s%s",a+1,b+1);
	n= strlen(a+1);
	m= strlen(b+1);
	for (i= 1;i<=m;i++)
		s[i]= s[i-1]+(b[i]=='1');
	k= m-n+1;
	for (i= 1;i<=n;i++)
		if (a[i]=='0')
			ans+= (s[i+k-1]-s[i-1]);
		else ans+= k-(s[i+k-1]-s[i-1]);
	printf("%lld\n",ans);
	return 0;
}
