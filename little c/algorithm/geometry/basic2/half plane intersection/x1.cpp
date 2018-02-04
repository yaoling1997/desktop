#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;
const double eps= 1e-8;
struct point{
	double x,y;
};
typedef point vec;
int dcmp(double x){if (fabs(x)<eps) return 0;else return x<0 ? -1:1;}
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*=t; a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<0 || (dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)<0);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
typedef vector<point> polygon;
struct line{
	point p;
	vec v;
	double ang;
};
bool os(point a,point b,point p){
	if (dcmp(cj(b-a,p-a))==0){
		if (b<a) swap(a,b);
		if (dcmp(p.x-a.x)>=0 && dcmp(p.x-b.x)<=0) return 1;
	}
	return 0;
}
point jd(point p,vec v,point q,vec w){
	vec u= p-q;
	return p+cj(w,u)/cj(v,w)*v;
}
polygon CutPolygon(polygon poly,point a,point b){
	polygon newpoly;
	int n= poly.size();
	poly.push_back(poly[0]);
	for (int i= 0;i<=n;i++){
		point c= poly[i];
		point d= poly[i+1];
		if (dcmp(cj(b-a,c-a))>=0) newpoly.push_back(c);
		if (dcmp(cj(b-a,c-d))!=0){
			point p= jd(a,b-a,c,d-c);
			if (os(c,d,p)) newpoly.push_back(p);
		}
	}
	return newpoly;
}
int main()
{
	
}
