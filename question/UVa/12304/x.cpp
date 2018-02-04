#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
const double eps= 1e-10,PI= 2*acos(0.0),pi= 180;
const int maxn= 3001,oo= 1e8;
struct point{
	double x,y;
};
typedef point vec;
struct circle{
	point c;
	double r;
	point getpoint(double a){
		return (point){c.x+r*cos(a),c.y+r*sin(a)};
	}
};
vector<point> sol;
char s[100];
double x1,x2,x3,x4,x5,x6,x7,x8,x9;
int X;
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
double length(vec a){return sqrt(dj(a,a));}
point jd(point p,point v,point q,point w){
	vec u= p-q;
	return p+cj(w,u)/cj(v,w)*v;
}
point fp(point a,point b,point p){
	vec v= b-a;
	return a+dj(p-a,v)/dj(v,v)*v;
}
double angle(vec a,vec b){
	return acos(dj(a,b)/length(a)/length(b));
}
double polarAngle(vec a){
	return atan2(a.y,a.x);
}
double radian(double x){return x*180/PI;}
double dist1(point a,point b,point p){
	return fabs(cj(b-a,p-a)/length(b-a));
}
int tangents(circle c,point p,double *V){
	point o= c.c;
	double r= c.r,d= length(o-p);
	if (dcmp(d-r)<0) return 0;
	vec v= o-p;
	if (!dcmp(d-r)){
		V[1]= radian(polarAngle(rot(v,PI/2)));
		if (dcmp(V[1])<0) V[1]+= pi;
		if (!dcmp(V[1]-pi)) V[1]-= pi;
		return 1;
	}
	double da= asin(r/d);
	V[1]= radian(polarAngle(rot(v,da)));
	V[2]= radian(polarAngle(rot(v,-da)));
	if (V[1]<0) V[1]+= pi;
	if (V[2]<0) V[2]+= pi;
	if (!dcmp(V[1]-pi)) V[1]-= pi;
	if (!dcmp(V[2]-pi)) V[2]-= pi;	
	if (V[2]<V[1]) swap(V[1],V[2]);
	return 2;
}
int lci(point a,point b,circle c){
	sol.clear();
	point o= c.c,p= fp(a,b,o);
	double r= c.r,d= dist1(a,b,o);
	if (dcmp(d-r)>0) return 0;
	if (!dcmp(d-r)){
		sol.push_back(p);
		return 1;
	}
	double l= sqrt(r*r-d*d);
	vec v= l*(b-a)/length(b-a);
	sol.push_back(p+v);
	sol.push_back(p-v);
	if (sol[1]<sol[0]) swap(sol[0],sol[1]);
	return 2;
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
	double base= polarAngle(o2-o1),da= acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	point p1= c1.getpoint(base+da),p2= c1.getpoint(base-da);
	sol.push_back(p1);
	if (p1==p2)
		return 1;
	sol.push_back(p2);
	if (sol[1]<sol[0]) swap(sol[0],sol[1]);
	return 2;
}
bool cmp(vec a,vec b){return a<b;}
void get1(){
	point p1,p2,p3,mid1,mid2;
	p1= (point){x1,x2};
	p2= (point){x3,x4};
	p3= (point){x5,x6};
	mid1= (p1+p2)/2,mid2= (p1+p3)/2;
	vec v1= rot(p2-p1,PI/2),v2= rot(p3-p1,PI/2);
	p1= jd(mid1,v1,mid2,v2);
	double r= length(p2-p1);
	printf("(%.6lf,%.6lf,%.6lf)\n",p1.x, p1.y, r);
}
void get2(){
	point p1,p2,p3;
	p1= (point){x1,x2};
	p2= (point){x3,x4};
	p3= (point){x5,x6};
	double da1= angle(p2-p1,p3-p1)/2,da2= angle(p1-p2,p3-p2)/2;
	vec v1= p2-p1,v2= p3-p2;
	if (dcmp(cj(p2-p1,p3-p1))>0) v1= rot(v1,da1);
	else v1= rot(v1,-da1);
	if (dcmp(cj(p3-p2,p1-p2))>0) v2= rot(v2,da2);
	else v2= rot(v2,-da2);
	p1= jd(p1,v1,p2,v2);
	double r= dist1(p2,p3,p1);
	printf("(%.6lf,%.6lf,%.6lf)\n",p1.x,p1.y,r);
}
void get3(){
	circle c= (circle){x1,x2,x3};
	point p= (point){x4,x5};
	double V[3]= {0};
	int m= tangents(c,p,V),i;
	printf("[");
	for (i= 1;i<=m;i++){
		printf("%.6lf",V[i]);
		if (i!=m) printf(",");
	}printf("]\n");
}
void get4(){
	circle c= (circle){(point){x1,x2},x7};
	point p1= (point){x3,x4},p2= (point){x5,x6};
	double r= c.r;
	vec v= rot(p2-p1,PI/2);
	v= r*v/length(v);
	int m= lci(p1+v,p2+v,c),i;
	m+= lci(p1-v,p2-v,c);
	printf("[");
	for (i= 0;i<m;i++){
		printf("(%.6lf,%.6lf)",sol[i].x, sol[i].y);
		if (i!=m-1) printf(",");
	}printf("]\n");
}
void get(point a1,point a2,point b1,point b2,double r){
	double da= angle(a2-a1,b2-b1)/2,l= r/sin(da);
	point p= jd(a1,a2-a1,b1,b2-b1);
	vec v= (a2-a1)/length(a2-a1);
	if (dcmp(cj(a2-a1,b2-b1))>0)
		v= rot(v,da);
	else v= rot(v,-da);
	sol.push_back(p+l*v);
}
void get5(){
	sol.clear();
	point a1= (point){x1,x2},a2= (point){x3,x4};
	point b1= (point){x5,x6},b2= (point){x7,x8};
	get(a1,a2,b1,b2,x9);
	get(a1,a2,b2,b1,x9);
	get(a2,a1,b1,b2,x9);
	get(a2,a1,b2,b1,x9);
	sort(sol.begin(),sol.end(),cmp);
	printf("[");
	for (int i= 0;i<=3;i++){
		printf("(%.6lf,%.6lf)",sol[i].x, sol[i].y);
		if (i!=3) printf(",");
	}printf("]\n");
}
void get6(){
	circle c1= (circle){(point){x1,x2},x3+x7};
	circle c2= (circle){(point){x4,x5},x6+x7};
	int m= cci(c1,c2);
	printf("[");
	for (int i= 0;i<m;i++){
		printf("(%.6lf,%.6lf)",sol[i].x,sol[i].y);
		if (i!=m-1) printf(",");
	}printf("]\n");
}
int change(char *s){
	if (s[1]=='C'){
		if (s[19]=='e') return 1;
		else if (s[19]=='t') return 4;
		else if (s[19]=='L') return 5;
		else return 6;
	}else if (s[1]=='T')return 3;
	else return 2;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%s",s+1)!=EOF){
		X= change(s);
		if (X==1){
			scanf("%lf %lf %lf",&x1, &x2, &x3);
			scanf("%lf %lf %lf",&x4, &x5, &x6);
			get1();
		}else if (X==2){
			scanf("%lf %lf %lf",&x1, &x2, &x3);
			scanf("%lf %lf %lf",&x4, &x5, &x6);			
			get2();
		}else if (X==3){
			scanf("%lf %lf %lf %lf %lf",&x1, &x2, &x3, &x4, &x5);
			get3();
		}else if (X==4){
			scanf("%lf %lf %lf",&x1, &x2, &x3);
			scanf("%lf %lf %lf %lf",&x4, &x5, &x6, &x7);
			get4();
		}else if (X==5){
			scanf("%lf %lf %lf %lf",&x1, &x2, &x3, &x4);
			scanf("%lf %lf %lf %lf %lf",&x5, &x6, &x7, &x8, &x9);
			get5();
		}else {
			scanf("%lf %lf %lf",&x1, &x2, &x3);
			scanf("%lf %lf %lf %lf",&x4, &x5, &x6, &x7);
			get6();
		}
	}
	return 0;
}
