#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn= 3001;
const double eps= 1e-8,rad= 0.33333,pi= 3.141592654;
struct point{
	double x,y;
};
typedef point vec;
point a,b,c,d,e,f;
vec l1,l2;
double jj1,jj2,jj3;
int t;
double dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator ==(vec a,vec b){
	return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);
}
bool operator <(vec a,vec b){
	return dcmp(a.x-b.x)<0 || (!dcmp(a.x-b.x) && dcmp(a.y-b.y)<0);
}
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
point jd(point p,vec v,point q,vec w){
	vec u= p-q;
	return p+ cj(w,u)/cj(v,w)*v;
}
double length(vec a){return sqrt(dj(a,a));}
double angle(vec a,vec b){return acos(dj(a,b)/length(a)/length(b));}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for (int tt= 1;tt<=t;tt++){
		scanf("%lf %lf %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
		jj1= angle(b-a,c-a);
		jj2= angle(a-b,c-b);
		jj3= angle(a-c,b-c);
		l1= rot(b-a,jj1/3);
		l2= rot(a-b,-jj2/3);
		f= jd(a,l1,b,l2);
		l1= rot(c-a,-jj1/3);
		l2= rot(a-c,jj3/3);
		e= jd(a,l1,c,l2);
		l1= rot(c-b,jj2/3);
		l2= rot(b-c,-jj3/3);
		d= jd(b,l1,c,l2);
		printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",d.x, d.y, e.x, e.y, f.x, f.y);
	}
	return 0;
}
