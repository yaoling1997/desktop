#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double oo= 1e9;
const int maxn= 3001;
double k1,k2,ans,now;
int n,m,i,x,y,z,xx,yy,a1,a2;
double sqr(double a){return a*a;}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lf %lf %d %d",&k1, &k2, &m, &n);
	if (n%m==0)
		ans= n*sqr(100.0/n)*k2+m*sqr(100.0/m)*k1;
	else {
		ans= oo;
		y= n%m;x= m-y;z= n/m;
		xx= z*x;yy= (z+1)*y;
		for (i= xx;i<=100-yy;i++){
			now= 0;
			a1= i/x;a2= i%x;
			now+= sqr(a1)*(x-a2)*k1;
			if (a2) now+= sqr(a1+1)*a2*k1;
			a1= i/xx;a2= i%xx;
			now+= sqr(a1)*(xx-a2)*k2;
			if (a2) now+= sqr(a1+1)*a2*k2;
			a1= (100-i)/y;a2= (100-i)%y;
			now+= sqr(a1)*(y-a2)*k1;
			if (a2) now+= sqr(a1+1)*a2*k1;
			a1= (100-i)/yy;a2= (100-i)%yy;
			now+= sqr(a1)*(yy-a2)*k2;
			if (a2) now+= sqr(a1+1)*a2*k2;
			ans= min(ans,now);
		}
	}printf("%.1lf",ans);
	return 0;
}
