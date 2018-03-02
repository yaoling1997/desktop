#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
const double eps= 1e-8;
struct point{
	double x,y;
};
typedef point vec;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return a.x<b.x || (a.x==b.x && a.y<b.y);}
int dcmp(double x){if (fabs(x)<eps)return 0;return x<0 ? -1:1;}
bool operator ==(vec a,vec b){return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dj(a,a));}
double angle(vec a,vec b){
	return acos(dj(a,b)/length(a)/length(b));
}
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
double dist1(point a,point b,point p){return cj(b-a,p-a)/length(b-a);}
double dist2(point a,point b,point p){
	if (dj(b-a,p-a)<0) return length(p-a);
	if (dj(a-b,p-b)<0) return length(p-b);
	return dist1(a,b,p);
}
point jd(point p,vec v,point q,vec w){
	vec u= p-q;
	double t= cj(w,u)/cj(v,w);
	return p+t*v;
}
point fp(point a,point b,point p){
	vec v= b-a;
	return a+dj(v,p-a)/dj(v,v)*v;
}
bool xj(point a1,point a2,point b1,point b2){
	double x1= cj(a2-a1,b1-a1),x2= cj(a2-a1,b2-a1);
	double y1= cj(b2-b1,a1-b1),y2= cj(b2-b1,a2-b1);
	return dcmp(x1)*dcmp(x2)<0 && dcmp(y1)*dcmp(y2)<0;
}
bool onSegment(point a,point b,point p){
	return !dcmp(cj(b-a,p-a)) && dcmp(dj(a-p,b-p))<0;
}//考虑的线段都不包含端点
point g,a,ans;
double R,x,y,r;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%lf%lf%lf",&R,&x,&y);
	g=(point){x,y};
	scanf("%lf%lf",&x, &y);
	a=(point){x,y};
	double len= length(a-g);
	if (len>R){
		ans=g;
		r=R;
	}else {
		r=(min(len,R)+R)/2;
		vec v;
		if (!(g==a))
			v=(g-a)/length(g-a);
		else
			v=(vec){1,0};
		 ans=a+r*v;
	}
	printf("%.16f %.16f %.16f",ans.x, ans.y, r);
	return 0;
}
