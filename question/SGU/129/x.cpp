#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e4;
const double eps= 1e-8;
struct point{
	double x,y;
}p[maxn],ch[maxn],sta[maxn];
typedef point vec;
point a,b,q;
int n,m,i,j,M,ai,bi,la;
double x,y,ans;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
bool operator ==(vec a,vec b){
	return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);
}
bool operator <(vec a,vec b){
	return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);
}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double length(vec a){return sqrt(dj(a,a));}
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
point jd(point p,vec v,point q,vec w){
	vec u= p-q;
	double t= cj(w,u)/cj(v,w);
	return p+t*v;
}
bool ipos(point a,point b,point p){
	if (a==p||b==p) return 1;
	return !dcmp(cj(b-a,p-a))&&dcmp(dj(a-p,b-p))<0;
}
int ipip(point *P,int n,point p){
	int wn= 0;
	int i;
	P[n+1]= P[1];
	for (i= 1;i<=n;i++){
		if (ipos(P[i],P[i+1],p)) return -1;
		double k= cj(P[i+1]-P[i],p-P[i]);
		double d1= P[i].y-p.y;
		double d2= P[i+1].y-p.y;
		if (k>0&&d1<=0&&d2>0) wn++;
		if (k<0&&d2<=0&&d1>0) wn--;
	}return wn;
}
bool xj(point a1,point a2,point b1,point b2){
	if (ipos(b1,b2,a1)||ipos(b1,b2,a2)) return 1;
	double x1= cj(a2-a1,b1-a1),x2= cj(a2-a1,b2-a1);
	double y1= cj(b2-b1,a1-b1),y2= cj(b2-b1,a2-b1);
	return dcmp(x1*x2)<0&&dcmp(y1*y2)<0;
}
void rp(point &a){
	double x,y;
	scanf("%lf%lf",&x, &y);
	a= (point){x,y};
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%lf%lf",&p[i].x, &p[i].y);
	sort(p+1,p+n+1);
	for (i= 1;i<=n;i++){
		while (m>1&&dcmp(cj(ch[m]-ch[m-1],p[i]-ch[m-1]))<=0) m--;
		ch[++m]= p[i];
	}
	int k= m;
	for (i= n-1;i>0;i--){
		while (m>k&&dcmp(cj(ch[m]-ch[m-1],p[i]-ch[m-1]))<=0) m--;
		ch[++m]= p[i];
	}	
	if (m>2) m--;
	scanf("%d",&M);
	ch[m+1]= ch[1];
	for (int mm= 1;mm<=M;mm++){
		ans= 0;
		rp(a);
		rp(b);
		la= 0;
		sta[++la]= a;
		sta[++la]= b;
		for (i= 1;i<=m;i++){
			if (!dcmp(cj(ch[i+1]-ch[i],b-a))) continue;
			if (xj(ch[i],ch[i+1],a,b))
				sta[++la]= jd(ch[i],ch[i+1]-ch[i],a,b-a);			
		}
		sort(sta+1,sta+la+1);
		for (i= 2;i<=la;i++){
			q= (sta[i]+sta[i-1])/2;
			if (ipip(ch,m,q)==1) ans+= length(sta[i]-sta[i-1]);
		}
		printf("%.2lf\n",ans);
	}return 0;
}
