#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
struct point3{
	double x,y,z;
};
typedef point3 vec3;
struct plane{
	point p0;
	vec n;//n为单位向量
}
vec3 operator +(vec3 a,vec3 b){a.x+= b.x;a.y+= b.y;a.z+= b.z;return a;}
vec3 operator -(vec3 a,vec3 b){a.x-= b.x;a.y-= b.y;a.z-= b.z;return a;}
vec3 operator *(double t,vec3 a){a.x*= t;a.y*= t;return a;}
vec3 operator /(vec3 a,double t){a.x/= t;a.y/= t;return a;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y+a.z*b.z;}
double length(vec3 a){return sqrt(dj(a,a));}
double angle(vec a,vec b){return acos(dj(a,b)/length(a)/length(b));}
double distplane(point p0,vec n,point a){
	return fabs(dj(a-p0,n));
}
point3 projection(point3 p,point3 p0,vec3 n){
	return p-dj(p-p0,n)*n;
}
point3 lpis(point3 p0,vec n,point3 p1,point3 p2){
	vec3 v= p2-p1;
	double t= dj(n,p0-p1)/dj(p2-p1);
	return p1+t*v;
}
vec3 cj(vec3 a,vec3 b){
	return (vec3){a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x;}
}
double area(point3 a,point3 b,point3 c){
	return length(cj(b-a,c-a));
}

int main()
{
	
}
