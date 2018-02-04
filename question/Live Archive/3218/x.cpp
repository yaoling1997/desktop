#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-7,PI= acos(-1);
const int maxn= 3e2;
struct point{
	double x,y;
}P[maxn],ans[maxn],sta[maxn];
typedef point vec;
int i,j,n,m,o,la;
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
point jd(point p,vec v,point q,vec w){
	vec u= p-q;
	double t= cj(w,u)/cj(v,w);
	return p+t*v;
}
bool onSeg(point a,point b,point p){
	return !dcmp(cj(b-a,p-a))&&dcmp(dj(p-a,p-b))<=0;
}
bool xj(point a1,point a2,point b1,point b2){
	double x1= cj(a2-a1,b1-a1),x2= cj(a2-a1,b2-a1);
	double y1= cj(b2-b1,a1-b1),y2= cj(b2-b1,a2-b1);
	return dcmp(x1*x2)<0&&dcmp(y1*y2)<0;
}
double angle(vec u,vec v){
	double x= acos(1.1);
	x= dj(u,v)/length(u)/length(v);
	if (x>1) x= 1;
	if (x<-1) x= -1;
	double da= acos(x);
	//double re= asin(cj(u,v)/length(u)/length(v));
	double re= da;
	if (dcmp(cj(u,v))<0) re= -da;
	if (dcmp(re)<=0) re+= 2*PI;
	return re;
}
double area(point *P,int n){
	int i;
	double area= 0;
	P[n+1]= P[1];
	for (i= 2;i<n;i++)
		area+= cj(P[i]-P[1],P[i+1]-P[1]);
	return area/2;
}
bool ok(point O,point q){
	int i,j;
	m= 0;
	ans[++m]= O;
	point p= O;
	for (;;){
		vec v= q-p,u= -1*v;
		//sta[la=1]= q;
		for (i= 1;i<=n;i++)
			if (xj(P[i],P[i+1],p,q))
				q= jd(p,v,P[i],P[i+1]-P[i]);
		j= 0;
		for (i= 1;i<=n;i++)
			if (onSeg(P[i],P[i+1],q)){
				if (!(P[i]==q)){
					if (!j||angle(u,P[j]-q)>angle(u,P[i]-q))
						j= i;
				}
				if (!(P[i+1]==q)){
					if (!j||angle(u,P[j]-q)>angle(u,P[i+1]-q))
						j= i+1;					
				}				
			}
		p= q;
		q= P[j];
		if (p==O) break;		
		ans[++m]= p;
	}
	return area(ans,m)>0;
}
void print(){
	int i;
	printf("%d\n",m);
	for (i= 1;i<=m;i++)
		printf("%.4lf %.4lf\n",ans[i].x, ans[i].y);
}
void init(){
	o= 1;
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		init();
		for (i= 1;i<=n;i++){
			scanf("%lf%lf",&P[i].x, &P[i].y);
			if (P[i]<P[o])
				o= i;
		}
		P[n+1]= P[1];
		P[0]= P[n];
		if (ok(P[o],P[o+1])) print();
		else {
			ok(P[o],P[o-1]);
			print();
		}
	}return 0;
}
