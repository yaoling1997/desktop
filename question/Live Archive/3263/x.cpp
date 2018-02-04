#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-8;
const int maxn= 500;
struct point{
	double x,y;
};
typedef point vec;
point p[maxn],P[maxn*maxn];
int n,ans,i,j,k,cnt,m,e,f;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
bool operator <(vec a,vec b){
	return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);
}
bool operator ==(vec a,vec b){
	return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);
}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){
	return sqrt(dj(a,a));
}
double angle(vec a,vec b){
	return acos(dj(a,b)/length(a)/length(b));
}
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
double dist1(point a,point b,point p){
	return fabs(cj(b-a,p-a)/length(b-a));
}
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
	double t= dj(v,p-a)/dj(v,v);
	return a+t*v;
}
bool xj(point a1,point a2,point b1,point b2){
	double x1= cj(a2-a1,b1-a1),x2= cj(a2-a1,b2-a1);
	double y1= cj(b2-b1,a1-b1),y2= cj(b2-b1,a2-b1);
	return dcmp(x1*x2)<0&&dcmp(y1*y2)<0;
}
bool onSeg(point a,point b,point p){
	if (a==p||b==p) return 1;
	return !dcmp(cj(b-a,p-a))&&dcmp(dj(p-a,p-b))<0;
}
bool onSeg2(point a,point b,point p){
	return !dcmp(cj(b-a,p-a))&&dcmp(dj(p-a,p-b))<0;
}
bool cmp(vec a,vec b){
	return a<b;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		if (!n) break;
		cnt++;
		for (i= 1;i<=n;i++){
			scanf("%lf%lf",&p[i].x, &p[i].y);
			P[i]= p[i];
		}
		m= n;
		n--;
		for (i= 1;i<=n;i++){
			vec v= p[i+1]-p[i];
			for (j= i+1;j<=n;j++){
				vec w= p[j+1]-p[j];
				if (!dcmp(atan2(v.y,v.x)-atan2(w.y,w.x))) continue;
				point q= jd(p[i],v,p[j],w);
				if (onSeg(p[i],p[i+1],q)&&onSeg(p[j],p[j+1],q))
					P[++m]= q;
			}
		}
		sort(P+1,P+m+1,cmp);
		i= 1;
		for (j= 2;j<=m;j++){
			if (P[i]==P[j]) continue;
			P[++i]= P[j];
		}
		m= i;
		e= n;
		for (i= 1;i<=n;i++)
			for (j= 1;j<=m;j++)
				if (onSeg2(p[i],p[i+1],P[j]))
					e++;
		f= e-m+2;
		printf("Case %d: There are %d pieces.\n",cnt,f);
	}return 0;
}
