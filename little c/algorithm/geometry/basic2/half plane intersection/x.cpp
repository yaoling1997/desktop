#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const double eps= 1e-8,rad= 0;
const int maxn= 3001;
struct point{
	double x,y;
};
typedef point vec;
struct line{
	point p;
	vec v;
	double ang;
	void askang(){ang= atan2(v.y,v.x);}
};
line l[maxn],q[maxn];
point poly[maxn],p[maxn];
int i,n,m;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<0 || (dcmp(a.x-b.x==0) && dcmp(a.y-b.y)<0);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
point jd(line a,line b){
	vec u= a.p-b.p;
	return a.p+cj(b.v,u)/cj(a.v,b.v)*a.v;
}
bool onleft(line a,point p){
	return dcmp(cj(a.v,p-a.p))>0;
}
bool cmpl(line a,line b){return a.ang<b.ang;}
int hpi(){//halfplaneintersection
	sort(l+1,l+n+1,cmpl);
	int first= 1,last= 1,i;
	q[1]= l[1];
	for (i= 2;i<=n;i++){
		while (first<last && !onleft(l[i],p[last-1]))
			last--;
		while (first<last && !onleft(l[i],p[first]))
			first++;
		q[++last]= l[i];
		if (!dcmp(cj(q[last].v,q[last-1].v))){//不需要加first<last,因为显然<
			last--;
			if (onleft(q[last],l[i].p)) q[last]= l[i];
		}
		if (first<last)
			p[last-1]= jd(q[last-1],q[last]);
	}
	while (first+1<last && !onleft(q[first],p[last-1]))
		last--;
	if (last-first<=1) return 0;
	//if (dcmp(cj(q[first].v,q[last].v))>0) return 0;判无界多边形
	p[last]= jd(q[last],q[first]);
	int m= 0;
	for (i= first;i<=last;i++)
		poly[++m]= p[i];
	return m;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		point a1,a2;
		scanf("%lf %lf %lf %lf",&a1.x, &a1.y, &a2.x, &a2.y);
		a1= rot(a1,rad);
		a2= rot(a2,rad);
		l[i].p= a1;l[i].v= a2-a1;
		l[i].askang();
	}
	m= hpi();
	for (i= 1;i<=m;i++){
		poly[i]= rot(poly[i],-rad);
		if (dcmp(poly[i].x)==0) poly[i].x= 0;
		if (dcmp(poly[i].y)==0) poly[i].y= 0;
		printf("%.5lf %.5lf\n",poly[i].x, poly[i].y);
	}
	return 0;
}
