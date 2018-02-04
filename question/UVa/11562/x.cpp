#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 3001,oo= 1e9;
const double eps= 1e-8,pi= acos(-1);
struct point{
	double x,y;
};
struct circle{
	point c;
	double r;
	point getpoint(double a){
		return (point){c.x+r*cos(a),c.y+r*sin(a)};
	}
};
typedef point vec;
vector<point> sol;
circle CC;
int i,j,n;
point P[maxn],O;
double x,y,ans,R;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);}
bool operator ==(vec a,vec b){return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double operator *(vec a,vec b){return dj(a,b);}
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
double length(vec a){
	return sqrt(dj(a,a));
}
point jd(point p,vec v,point q,vec w){
	vec u= p-q;
	return p+cj(w,u)/cj(v,w)*v;
}
point fp(point a,point b,point p){
	vec v= b-a;
	return a+dj(p-a,v)/dj(v,v)*v;
}
double polarAngle(vec a){
	return atan2(a.y,a.x);
}
double jj(vec a,vec b){
	double re= fabs(polarAngle(a)-polarAngle(b));
	if (re>pi) re= 2*pi-re;
	return re;
	}
double getAngle(point a,point b,point c){
	double re= fabs(polarAngle(b-a)-polarAngle(c-a));
	if (re>pi) re= 2*pi-re;
	return re;
}
bool sameSide(point a,point b,point p,point q){
	return dcmp(cj(b-a,p-a)*cj(b-a,q-a))>0;
}
void update(point p,point q){
	point m= (p+q)/2,o;
	vec v= (p-q)/length(p-q);
	v= rot(v,pi/2);
	double l= length(p-q);
	double a= v*m/R;
	double b= (R*R/2+m*m/2-l*l/8)/R;
	double A= a*a-1;
	double B= 2*a*b-2*m*v;
	double C= b*b-m*m;
	double data= B*B-4*A*C;
	double t1= (-B+sqrt(data))/(2*A);
	double t2= (-B-sqrt(data))/(2*A);
	double d= length(m);
	double r= l/2,x;
	if (dcmp(d-(R-r))<=0){
		o= m+t1*v;
		x= getAngle(o,p,q)/2;
		ans= max(ans,x);
		o= m+t2*v;
		x= getAngle(o,p,q)/2;
		ans= max(ans,x);
	}else {
		point o1= m+t1*v;
		point o2= m+t2*v;
		if (length(o1-p)>length(o2-p)) swap(o1,o2);
		x= pi-getAngle(o1,p,q)/2;
		ans= max(ans,x);
		x= getAngle(o2,p,q)/2;
		ans= max(ans,x);
	}
}
void init(){
	ans= -oo;
}
int main()
{
	while (scanf("%d%lf",&n, &R)>0){
		init();
		CC= (circle){O,R};
		for (i= 1;i<=n;i++){
			scanf("%lf%lf",&x, &y);
			P[i]= (point){x,y};
		}
		for (i= 1;i<=n;i++)
			for (j= i+1;j<=n;j++)
				update(P[i],P[j]);			
		printf("%.10lf\n",ans);
	}
	return 0;
}

