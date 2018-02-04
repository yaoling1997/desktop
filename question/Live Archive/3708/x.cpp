#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn= 3001;
double a[maxn];
int n,m,i;
double ans,a1,a2,cnt;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while(scanf("%d %d",&n, &m)!=EOF){
		ans= 0;cnt= 0;
		a1= 1.0/n;a2= 1.0/(n+m);
		for (i= 1;i<n;i++)
			a[i]= a[i-1]+a1;
		for (i= 1;i<n;i++){
			while (cnt+a2<a[i]) cnt+= a2;
			ans+= min(abs(a[i]-cnt),abs(a[i]-cnt-a2));
		}
		printf("%.4lf\n",ans*10000);
	}
	return 0;
}
