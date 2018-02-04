#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double eps= 1e-8;
int n,T;
double D,H,B,L,l,r,h,a,w;
double F(double x){
	return sqrt(1+4*a*a*x*x);
}
double simpson(double a,double b){
	double c= (a+b)/2;
	return (F(a)+4*F(c)+F(b))*(b-a)/6;
}
double asr(double a,double b,double eps,double A){
	double c= (a+b)/2,L= simpson(a,c),R= simpson(c,b);
	if (fabs(L+R-A)<eps) return L+R;
	return asr(a,c,eps,L)+asr(c,b,eps,R);
	
}
double get(){
	a= 4*h/w/w;
	return 2*asr(0,w/2,eps,simpson(0,w/2));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%lf %lf %lf %lf",&D, &H, &B, &L);
		n= ceil(B/D);
		L/= n;w= B/n;
		l= 0;r= H;
		while (r-l>eps){
			h= (l+r)/2;
			if (get()>L) r= h;
			else l= h;
		}//printf("Case %d:%.2lf\n",a1, H-l);
		if (a1>1) printf("\n");
		printf("Case %d:\n%.2lf\n",a1, H-l);		
	}return 0;
}
