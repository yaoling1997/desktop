#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ld long double
using namespace std;
const ld eps= 1e-12;
ld u,a,b,sin1,sin2,W,H,x,xe,ye;
int T,i,j;
ld dist(ld x,ld y,ld xx,ld yy){
	ld X= x-xx,Y= y-yy;
	return sqrt(X*X+Y*Y);
}
bool ok(ld h){
	ld L= (H-h)*tan(b)+h*tan(a);
	return W-L>x;
}
int main()
{
	scanf("%d",&T);
	while (T--){
		scanf("%Lf%Lf%Lf%Lf%Lf",&W, &H, &x, &xe, &ye);
		scanf("%Lf",&u);
		sin1= (xe-W)/dist(W,H,xe,ye);
		sin2= sin1/u;		
		a= asin(sin2);
		b= asin(sin1);
		if (!ok(H)){
			printf("Impossible\n");
			continue;
		}
		ld l= 0,r= H;
		while (fabs(r-l)>eps){
			ld mid= (l+r)/2;
			if (ok(mid)) r= mid;
			else l= mid;
		}
		printf("%.4Lf\n",r);
	}return 0;
}
