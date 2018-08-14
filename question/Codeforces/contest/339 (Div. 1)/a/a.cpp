#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const double pi= acos(-1);
const int maxn= 2e5;
struct point{
	double x,y;
}P[maxn];
typedef point vec;
point o;
double R,r,ans;
int n,i;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){
	return sqrt(dj(a,a));
}
double dist(point a,point b){
	return length(b-a);
}
double dist1(point a,point b,point p){
	if (dj(b-a,p-a)<0) return dist(a,p);
	if (dj(a-b,p-b)<0) return dist(b,p);
	return fabs(cj(b-a,p-a)/length(b-a));
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%lf%lf",&n, &o.x, &o.y);
	for (i= 1;i<=n;i++){
		scanf("%lf%lf",&P[i].x, &P[i].y);
		R= max(R,dist(o,P[i]));
	}
	P[n+1]= P[1];
	r= R;
	for (i= 1;i<=n;i++)
		r= min(r,dist1(P[i],P[i+1],o));
	ans= R*R*pi-r*r*pi;
	printf("%.10lf",ans);
}
