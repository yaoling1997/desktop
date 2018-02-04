#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-10,PI= acos(-1);
const int maxn= 1000;
struct point{
	double x,y,z;
};
struct circle{
	point c;
	double r;
}C[maxn];
typedef point vec;
point P[maxn];
int Q[maxn];
int ans[maxn];
point o,v,p,q,M,N;
double x,y,z,r;
int i,j,k,n,m,la,bl;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;a.z+= b.z;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;a.z-= b.z;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;a.z*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;a.z/= t;return a;}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
double dj(vec a,vec b){
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
double length(vec a){
	return sqrt(dj(a,a));
}
void getjd(point p,vec v,int i){
	v= v/length(v);
	point o= C[i].c;
	double r= C[i].r,d= length(o-p);
	if (dcmp(dj(o-p,v))<0) return;
	double ang= acos(dj(o-p,v)/length(o-p)/length(v));
	double d1= d*sin(ang);
	if (dcmp(d1-r)>0) return;
	if (!dcmp(d1-r)){
		P[++la]= p+d*cos(ang)*v;
		Q[la]= i;
		return;
	}
	double l= sqrt(r*r-d1*d1);
	P[++la]= p+(d*cos(ang)-l)*v;
	Q[la]= i;	
	P[++la]= p+(d*cos(ang)+l)*v;
	Q[la]= i;
}
point get(point o,point p,point q){
	vec v= q-p;
	double t= dj(v,o-p)/dj(v,v);
	return p+t*v;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%lf%lf%lf%lf",&x, &y, &z, &r);
		C[i]= (circle){(point){x,y,z},r};
	}
	scanf("%lf%lf%lf",&x, &y, &z);
	o= (point){x,y,z};
	scanf("%lf%lf%lf",&x, &y, &z);
	v= (vec){x,y,z};
	v= v-o;
	m= 0;
	for (;;){
		la= 0;
		for (i= 1;i<=n;i++)
			getjd(o,v,i);
		bl= 0;
		for (i= 1;i<=la;i++)
			if (dcmp(dj(v,P[i]-o))>0&&(!bl||dj(v,P[i]-o)<dj(v,q-o))){
				q= P[i];
				j= Q[i];
				bl= 1;
			}
		if (!bl) break;
		p= C[j].c;
		M= get(o,p,q);
		N= 2*M-o;
		o= q;
		v= N-o;
		ans[++m]= j;
		if (m>10) break;
	}
	if (m>10){
		for (i= 1;i<=10;i++)
			printf("%d ",ans[i]);
		printf("etc.\n");
	}else {
		for (i= 1;i<=m;i++)
			printf("%d%c",ans[i],i<m?' ':'\n');
	}return 0;
}
