#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ld double
using namespace std;
const ld eps= 1e-7,oo= 1e9;
const int maxn= 3001;
ld X1,Y1,X2,Y2,vx,vy,wx,wy,t,v,l,r,ooo,cnt;
ld sqr(ld x){
	return x*x;
}
bool ok(ld tt){
	ld x= X1+vx*min(t,tt)+wx*max(tt-t,(ld)0);
	ld y= Y1+vy*min(t,tt)+wy*max(tt-t,(ld)0);
	return sqr(x-X2)+sqr(y-Y2)<sqr(v*tt);
}
int main()
{
	//freopen("2.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lf%lf%lf%lf",&X1, &Y1, &X2, &Y2);
	scanf("%lf%lf",&v, &t);
	scanf("%lf%lf",&vx, &vy);
	scanf("%lf%lf",&wx, &wy);
	l= 0,r= oo;
	while (r-l>eps){
		ld mid= (l+r)/2;
		if (ok(mid)) r= mid;
		else l= mid;
		cnt++;
		if (cnt==100)
			ooo++;
		if (cnt==1000)
			ooo++;
	}
	printf("%.10lf",l);
	return 0;
}
