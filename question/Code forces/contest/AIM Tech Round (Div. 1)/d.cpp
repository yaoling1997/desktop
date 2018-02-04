#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 105;
double p[maxn],q[maxn],d[maxn];
double ans,now;
int i,j,k,n;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	now= 1;
	for (i= 1;i<=n;i++){
		scanf("%lf",&p[i]);
		p[i]/= 100;
		q[i]= 1-p[i];
		d[i]= q[i];
		now*= p[i];
	}
	ans= n*now;
	for (i= 1;i<=4e5;i++){
		int t= 1;
		for (j= 2;j<=n;j++)
			if (d[t]*p[t]*(1-d[j])<d[j]*p[j]*(1-d[t])) t= j;
		now= 1;
		for (j= 1;j<=n;j++)
			if (j!=t)
				now*= (1-d[j]);
			else now*= d[j]*p[j];
		d[t]*= q[t];
		ans+= (n+i)*now;
	}
	printf("%.10lf\n",ans);
	return 0;
}
