#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn= 3001,oo= 999999999;
double eps= 1e-8,rad= 0.333333333;
struct point{
	double x,y;
};
typedef point vec;
point p[maxn],ch1[maxn],ch2[maxn];
vec v,w;
int n,m,i,a1,a2;
double ans,g1,g2,po;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(double t,vec a){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return (a.x<b.x ||(a.x==b.x && a.y<b.y));}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
double length(vec a){return sqrt(dj(a,a));}
double angle(vec a,vec b){return acos(dj(a,b)/length(a)/length(b));}
bool cmp(vec a,vec b){return a<b;}
int inc(int a,int n){
	a++;
	if (a>n) a-= n;
	return a;
}
void convex(point* p,point* ch,int& n){
	int m= 0;
	for (int i= 1;i<=n;i++){
		while (m>1 && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<=0) m--;
		ch[++m]= p[i];
	}
	int k= m;
	for (int i= n-1;i>0;i--){
		while (m>k && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<=0) m--;
		ch[++m]= p[i];
	}
	if (m>1) m--;
	n= m;
}
void scan(point* p,point* ch,int& n){
	for (int i= 1;i<=n;i++){
		scanf("%lf %lf\n",&p[i].x, &p[i].y);
		p[i]= rot(p[i],rad);
	}
	sort(p+1,p+n+1,cmp);
	convex(p,ch,n);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d\n",&n, &m);
	scan(p,ch1,n);
	scan(p,ch2,m);
	for (i= 1;i<=n;i++)
		if (a1==0 || ch1[a1].x>ch1[i].x) a1= i;
	for (i= 1;i<=m;i++)
		if (a2==0 || ch2[a2].x<ch2[i].x) a2= i;
	ans= length(ch1[a1]-ch2[a2]);v.y= -1;w.y= 1;
	while (po<3.4415926){
		g1= angle(v,ch1[inc(a1,n)]-ch1[a1]);
		g2= angle(w,ch2[inc(a2,m)]-ch2[a2]);
		po+= min(g1,g2);
		if (fabs(g1-g2)<eps){
			ans= max(ans,length(ch1[a1]-ch2[inc(a2,m)]));
			ans= max(ans,length(ch1[inc(a1,n)]-ch2[a2]));
			ans= max(ans,length(ch1[inc(a1,n)]-ch2[inc(a2,m)]));
			a1= inc(a1,n);
			a2= inc(a2,m);
			v= rot(v,g1);
			w= rot(w,g1);
		}else if (g1<g2){
			ans= max(ans,length(ch1[inc(a1,n)]-ch2[a2]));
			a1= inc(a1,n);
			v= rot(v,g1);
			w= rot(w,g1);
		}else {
			ans= max(ans,length(ch1[a1]-ch2[inc(a2,m),m]));
			a2= inc(a2,m);
			v= rot(v,g2);
			w= rot(w,g2);
		}
	}
	printf("%.2lf",ans);
	return 0;
}
