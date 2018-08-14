#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 300;
char s[maxn];
ll a[maxn];
ll n,p,i,j,ans,now;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld%lld",&n, &p);
	for (i= 1;i<=n;i++){
		scanf("%s",s+1);
		if (strlen(s+1)>4) a[i]= 1;
	}
	for (i= n;i>0;i--)
		if (a[i]==1){
			now= 2*now+1;
			ans+= now*p/2;
		}else {
			now*= 2;
			ans+= now*p/2;
		}
	printf("%lld",ans);
}
