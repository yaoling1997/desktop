#include<cstdio>
#include<cstdlib>
#include<cmath>
//#define double long double
using namespace std;
const double eps= 1e-8,lim= 1e-10;
double p,q,r,s,t,u;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
double f(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%lf %lf %lf %lf %lf %lf",&p, &q, &r, &s, &t, &u)!=EOF){
		if (!dcmp(f(0))){
			printf("0.0000\n");
		}else if (!dcmp(f(1))){
			printf("1.0000\n");
		}else if (f(0)<0 || f(1)>0){
			printf("No solution\n");
		}else {
			double l= 0,r= 1;
			while (r-l>lim){
				double mid= (l+r)/2;
				if (dcmp(f(mid))<0) r= mid;
				else l= mid;
			}
			printf("%.4lf\n",l);
		}
	}
	return 0;
}
