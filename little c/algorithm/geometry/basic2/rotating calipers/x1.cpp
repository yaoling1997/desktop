#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn= 3001,oo= 499999999;
const double eps= 1e-8,rad= 0.33333333;
struct point {
	double x,y;
};
typedef point vec;
point p[maxn],ch[maxn];
vec v,w;
int n,m,i,j,a1,a2;
double g1,g2,po,ans= oo;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return (a.x<b.x) || (a.x==b.x && a.y<b.y);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dj(a,a));}
double angle(vec a,vec b){return acos(dj(a,b)/length(a)/length(b));}
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
double dist1(point a,point b,point p){return fabs(cj(b-a,p-a)/length(b-a));}
bool cmp(vec a,vec b){return a<b;}
void convexhull (point* p){
	int i;
	for (i= 1;i<=n;i++){
		while (m>1 && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<=0) m--;
		ch[++m]= p[i];
	}
	int k= m;
	for (i= n-1;i>0;i--){
		while (m>k && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<=0) m--;
		ch[++m]= p[i];
	}
	if (m>1) m--;
}
int inc(int a){a++;if (a>m) a-= m;return a;}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++)	{
		scanf("%lf %lf\n",&p[i].x,&p[i].y);
		p[i]= rot(p[i],rad);
	}
	sort(p+1,p+n+1);
	convexhull(p);
	for (i= 1;i<=m;i++){
		if (a1==0 || ch[a1].x>ch[i].x) a1= i;
		if (a2==0 || ch[a2].x<ch[i].x) a2= i;
	}
	ans= length(ch[a1]-ch[a2]);
	v.y= -1; w.y= 1;
	while (po<3.4425926){
		g1= angle(v,ch[inc(a1)]-ch[a1]);
		g2= angle(w,ch[inc(a2)]-ch[a2]);
		po+= min(g1,g2);
		if (fabs(g1-g2)<eps) {
			ans= min(ans,dist1(ch[a1],ch[a1]+v,ch[a2]));
			a1= inc(a1);
			a2= inc(a2);
			v= rot(v,g1);
			w= rot(w,g1);
		}else if (g1<g2){
			ans= min(ans,dist1(ch[a1],ch[a1]+v,ch[a2]));
			a1= inc(a1);
			v= rot(v,g1);
			w= rot(w,g1);
		}else {
			ans= min(ans,dist1(ch[a2],ch[a2]+w,ch[a1]));
			a2= inc(a2);
			v= rot(v,g2);
			w= rot(w,g2);
		}
	}
	printf("%lf",ans);
	return 0;
}
