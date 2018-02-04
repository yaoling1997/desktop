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
const int maxn= 1e5;
struct point{
	double x,y;
};
typedef point vec;
struct line{
	point p;
	vec v;
	double ang;
	void getang(){
		ang= atan2(v.y,v.x);
	}
	bool operator <(const line a)const{
		return ang<a.ang;
	}
};
point p[maxn],poly[maxn];
line q[maxn],l[maxn];
int n,i,j;
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
double length(vec a){return sqrt(dj(a,a));}
point jd(line a,line b){
	vec u= a.p-b.p;
	double t= cj(b.v,u)/cj(a.v,b.v);
	return a.p+t*a.v;
}
bool onleft(line a,point p){
	return dcmp(cj(a.v,p-a.p))>0;
}
int hpi(int n){
	sort(l+1,l+n+1);
	int first= 1,last= 1,i;
	q[1]= l[1];
	for (i= 2;i<=n;i++){
		while (first<last&&!onleft(l[i],p[last-1])) last--;
		while (first<last&&!onleft(l[i],p[first])) first++;
		q[++last]= l[i];
		if (!dcmp(cj(q[last-1].v,q[last].v))){
			last--;
			if (onleft(q[last],l[i].p))
				q[last]= l[i];
		}
		p[last-1]= jd(q[last-1],q[last]);
	}
	while (first+1<last&&!onleft(q[first],p[last-1])) last--;
	if (last-first<=1) return 0;
	p[last]= jd(q[first],q[last]);
	return 1;
}
int next(int o,int x){
	o+= x+1;
	if (o>n) o-= n;
	return o;
}
bool ok(int x){
	int i;
	for (i= 1;i<=n;i++){
		l[i].p= poly[i];
		l[i].v= poly[next(i,x)]-poly[i];
		l[i].getang();
	}
	return !hpi(n);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		for (i= 1;i<=n;i++)
			scanf("%lf%lf",&poly[i].x, &poly[i].y);
		reverse(poly+1,poly+n+1);
		int l= 0,r= n;
		while (l+1<r){
			int m= (l+r)>>1;
			if (ok(m)) r= m;
			else l= m;
		}
		printf("%d\n",r);
	}return 0;
}
