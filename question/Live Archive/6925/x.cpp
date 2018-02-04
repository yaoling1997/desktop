#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 20;
double pi= 3.1415926535898;
double a[maxn],b[maxn],vt,vf,A,B,gap,p,q,ans;
int c,C,i,j,slices,stacks,T;
double F(double a){
	int i;double re= 0;
	for (i= C+1;i>0;i--)
		re= re*a+b[i];
	re*= a;
	return re;
}
double getS(double x){
	double r= 0,re;
	for (int i= c;i>=0;i--)
		r= r*x+a[i];
	re= 1.0/2*r*r*sin(2*pi/slices)*slices;
	return re;
}
double getV(double s1,double s2){
	return 1.0/3*(s1+s2+sqrt(s1*s2))*gap;
}
void init(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	vt= vf= 0;
}
int main()
{
	scanf("%d",&T);
	for (int TT= 1;TT<=T;TT++){
		init();
		scanf("%d",&c);
		for (i= c;i>=0;i--) scanf("%lf",&a[i]);
		for (i= 0;i<=c;i++)
			for (j= 0;j<=c;j++)
				b[i+j]+= a[i]*a[j];
		C= 2*c;
		for (i= 0;i<=C;i++)
			b[i]*= pi;
		for (i= C+1;i>=1;i--)
			b[i]= b[i-1]/i;
		scanf("%lf%lf%d%d",&A,&B,&slices,&stacks);
		if (A>B) swap(A,B);
		vt= F(B)-F(A);
		gap= (B-A)/stacks;
		p= A;q= A+gap;
		for (i= 1;i<=stacks;i++){
			double s1= getS(p);
			double s2= getS(q);
			vf+= getV(s1,s2);
			p= q;q+= gap;
		}
		ans= fabs((vt-vf)/vt)*100;
		printf("Case %d: %.4lf\n",TT, ans);
	}return 0;
}
