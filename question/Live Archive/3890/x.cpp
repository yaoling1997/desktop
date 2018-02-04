#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double eps= 1e-8,lim= 1e-8,PI= 2*acos(0.0);
const int maxn= 3001,oo= 1e7;
struct point{
	double x,y;
};
typedef point vec;
struct line{
	point p;
	vec v,v1;
	double ang;
	void getAng(){ang= atan2(v.y,v.x);}
};
point p[maxn],pn[maxn];
line L[maxn],l[maxn],q[maxn];
int i,n;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ?-1:1;
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
point jd(line a,line b){
	vec u= a.p-b.p;
	return a.p+cj(b.v,u)/cj(a.v,b.v)*a.v;
}
double length(vec a){return sqrt(dj(a,a));}
double polarAngle(vec a){
	return atan2(a.y,a.x);
}
bool cmp(line a,line b){
	return a.ang<b.ang;
}
bool onleft(point p,line a){
	return dcmp(cj(a.v,p-a.p))>0;
}
int hpi(){
	int first= 1,last= 1,i;
	q[1]= l[1];
	for (i= 2;i<=n;i++){
		while (first<last&&!onleft(p[last-1],l[i])) last--;
		while (first<last&&!onleft(p[first],l[i])) first++;
		q[++last]= l[i];
		if (!dcmp(cj(q[last].v,q[last-1].v))){
			last--;
			if (!onleft(q[last].p,l[i]))
				q[last]= l[i];
		}
		p[last-1]= jd(q[last],q[last-1]);
	}
	while (first+1<last && !onleft(p[last-1],q[first])) last--;
	if (last-first<=1) return 0;
	else return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		if (!n) break;
		for (i= 1;i<=n;i++)
			scanf("%lf %lf",&pn[i].x, &pn[i].y);
		pn[n+1]= pn[1];
		for (i= 1;i<=n;i++){
			L[i].p= pn[i];
			L[i].v= pn[i+1]-pn[i];
			L[i].v1= rot(L[i].v,PI/2);
			L[i].v1= L[i].v1/length(L[i].v1);
			L[i].getAng();
		}
		sort(L+1,L+n+1,cmp);
		for (i= 1;i<=n;i++)
			l[i]= L[i];			
		double ll= 0,rr= 20000;
		while (rr-ll>lim){
			double mid= (ll+rr)/2;
			for (i= 1;i<=n;i++)
				l[i].p= L[i].p+mid*L[i].v1;
			if (!hpi()) rr= mid;
			else ll= mid;
		}
		printf("%.6lf\n",ll);
	}
	return 0;
}
