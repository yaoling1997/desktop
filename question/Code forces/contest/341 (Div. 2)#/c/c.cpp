#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 2e5;
double a[maxn],b[maxn];
double ans;
int n,p,x,y,i;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d %d",&n, &p);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&x, &y);
		b[i]= y-x+1;
		a[i]= y/p-(x-1)/p;
	}
	a[n+1]= a[1];b[n+1]= b[1];
	for (i= 1;i<=n;i++)
		ans+= (a[i]*b[i+1]+b[i]*a[i+1]-a[i]*a[i+1])/(b[i]*b[i+1]);
	printf("%.10lf",ans*1000*2);
	return 0;
}
