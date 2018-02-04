#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn= 1000001;
ll a[maxn],c[maxn];
ll x,ans,m;
int n,i;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		ans= m= 0;
		for (i= 1;i<=n;i++){
			scanf("%lld",&a[i]);
			m+= a[i];
		}
		m/= n;
		for (i= 2;i<=n;i++)
			c[i]= c[i-1]-m+a[i-1];
		sort(c+1,c+n+1);
		x= c[(i+1)/2];
		for (i= 1;i<=n;i++)
			ans+= abs(c[i]-x);
		printf("%lld\n",ans);
	}
	return 0;
}
