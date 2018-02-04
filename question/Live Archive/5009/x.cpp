#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps= 1e-8,lim= 1e-10,oo= 1e8;
const int maxn= 11001;
int a[maxn],b[maxn],c[maxn];
int T,i,n;
double f(double x){
	int i;
	double ans= -oo;
	for (i= 1;i<=n;i++)
		ans= max(ans,a[i]*x*x+b[i]*x+c[i]);
	return ans;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (i= 1;i<=n;i++)
			scanf("%d %d %d",&a[i], &b[i], &c[i]);
		double l= 0,r= 1000;
		while (r-l>lim){
			double m1= l+(r-l)/3;
			double m2= r-(r-l)/3;
			if (f(m1)<f(m2)) r= m2;else l= m1;
		}
		printf("%.4lf\n",f(l));
	}
	return 0;
}
