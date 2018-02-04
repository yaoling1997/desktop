#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 3001;
const double eps= 1e-8,PI= 2*acos(0.0);
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
bool xj(point a1,point a2,point b1,point b2){
	double x1= cj(a2-a1,b1-a1),x2= cj(a2-a1,b2-a1);
	double y1= cj(b2-b1,a1-b1),y2= cj(b2-b1,a2-b1);
	return dcmp(x1*x2)<0 && dcmp(y1*y2)<0;
}
int lci(point a,point b,circle c){
	sol.clear();
	point o= c.c,p= fp(a,b,o);
	double r= c.r,d= length(p-o);
	if (dcmp(d-r)>0) return 0;
	if (!dcmp(d-r)){
		sol.push_back(p);
		return 1;
	}
	vec v= (b-a)/length(b-a);
	double l= sqrt(r*r-d*d);
	sol.push_back(p+l*v);
	sol.push_back(p-l*v);
	if (sol[1]<sol[0]) swap(sol[0],sol[1]);	
	return 2;
}
double polarAngle(vec a){
	return atan2(a.y,a.x);
}
int cci(circle c1,circle c2){
	sol.clear();
	if (c1.r<c2.r) swap(c1,c2);
	point o1= c1.c,o2= c2.c;
	double r1= c1.r,r2= c2.r,d= length(o1-o2);
	if (!dcmp(d)){
		if (!dcmp(r1-r2)) return -1;
		else return 0;
	}
	if (dcmp(r1-r2-d)>0||dcmp(r1+r2-d)<0) return 0;
	double base= polarAngle(o2-o1);
	double da= acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	point p1= c1.getpoint(base+da),p2= c1.getpoint(base-da);
	sol.push_back(p1);
	if (p1==p2)		
		return 1;
	sol.push_back(p2);
	if (sol[1]<sol[0]) swap(sol[0],sol[1]);	
	return 2;
}
int tangents(point p,circle c,vec *V){
	point o= c.c;
	vec v= o-p;
	double r= c.r,d= length(v);
	if (dcmp(d-r)<0) return 0;
	else if (!dcmp(d-r)){
		V[1]= rot(v,PI/2);
		return 1;
	}
	double ang= asin(r/d);
	V[1]= rot(v,ang);
	V[2]= rot(v,-ang);
	return 2;	
}
int tangents(circle c1,circle c2,point *a,point *b){
	if (c1.r<c2.r) swap(c1,c2);
	point o1= c1.c,o2= c2.c;
	double r1= c1.r,r2= c2.r,d= length(o1-o2);
	if (dcmp(r1-r2-d)>0) return 0;
	if (!dcmp(d)&&!dcmp(r2-r1)) return -1;
	double base= polarAngle(o2-o1);
	if (!dcmp(r1-r2-d)){
		a[1]= c1.getpoint(base);b[1]= c2.getpoint(base);
		return 1;
	}
	double ang= acos((r1-r2)/d);
	a[1]= c1.getpoint(base+ang);b[1]= c2.getpoint(base+ang);
	a[2]= c1.getpoint(base-ang);b[2]= c2.getpoint(base-ang);
	if (dcmp(r1-r2-d)<0&&dcmp(r1+r2-d)>0)
		return 2;
	if (!dcmp(r1+r2-d)){
		a[3]= b[3]= c1.getpoint(base);
		return 3;
	}
	ang= acos((r1+r2)/d);
	a[3]= c1.getpoint(base+ang);b[3]= c2.getpoint(base+ang+PI);
	a[4]= c1.getpoint(base-ang);b[4]= c2.getpoint(base-ang+PI);
	return 4;	
}
int main()
{
	
}
