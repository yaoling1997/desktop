#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn= 3001,oo= 99999999;
const double rad= 0.3333333,eps= 1e-8;
struct point{
	double x,y;
};
typedef point vec;
point p1[maxn],p2[maxn],ch1[maxn],ch2[maxn];
vec v,w;
int i,m,n,a1,a2;
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
void convexhull(point* p,point* ch ,int &n){
	int i,m= 0;
	for (i= 1;i<= n;i++){
		while (m>1 && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<=0) m--;
		ch[++m]= p[i];
	}
	int k= m;
	for (i= n-1;i>0;i--){
		while (m>k && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<=0) m--;
		ch[++m]= p[i];
	}
	if (m>1) m--;
	n= m;
}
bool cmp(point a,point b){return a<b;}
int inc(int a,int n){
	a++;
	if (a>n) a-=n;
	return a;
}
double dist1(point a,point b,point p){
	return fabs(cj(b-a,p-a)/length(b-a));
}
double dist2(point a,point b,point p){
	if (dj(b-a,p-a)<0) return length(p-a);
	if (dj(a-b,p-b)<0) return length(p-b);
	return dist1(a,b,p);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d\n",&m, &n);
	for (i= 1;i<=m;i++){
		scanf("%lf %lf\n",&p1[i].x, &p1[i].y);
		p1[i]= rot(p1[i],rad);
	}
	for (i= 1;i<=n;i++){
		scanf("%lf %lf\n",&p2[i].x, &p2[i].y);
		p2[i]= rot(p2[i],rad);
	}
	sort(p1+1,p1+m+1,cmp);
	sort(p2+1,p2+n+1,cmp);
	convexhull(p1,ch1,m);
	convexhull(p2,ch2,n);
	for (i= 1;i<= m;i++){
		if (a1==0 || ch1[a1].x>ch1[i].x) a1= i;
	}
	for (i= 1;i<=n;i++){
		if (a2==0 || ch2[a2].x<ch2[i].x) a2= i;
	}
	v.y= -1; w.y= 1; ans= length(ch1[a1]-ch2[a2]);
	while (po<3.4415926){
		g1= angle(v,ch1[inc(a1,m)]-ch1[a1]);
		g2= angle(w,ch2[inc(a2,n)]-ch2[a2]);
		po+= min(g1,g2);
		if (fabs(g1-g2)<eps){
			ans= min(ans,dist2(ch1[a1],ch1[inc(a1,m)],ch2[a2]));
			ans= min(ans,dist2(ch1[a1],ch1[inc(a1,m)],ch2[inc(a2,n)]));
			ans= min(ans,dist2(ch2[a2],ch2[inc(a2,n)],ch1[a1]));
			ans= min(ans,dist2(ch2[a2],ch2[inc(a2,n)],ch1[inc(a1,m)]));
			a1= inc(a1,m);
			a2= inc(a2,n);
			v= rot(v,g1);
			w= rot(v,g2);
		}else if (g1<g2){
			ans= min(ans,dist2(ch1[a1],ch1[inc(a1,m)],ch2[a2]));
			a1= inc(a1,m);
			v= rot(v,g1);
			w= rot(w,g1);
		}else {
			ans= min(ans,dist2(ch2[a2],ch2[inc(a2,n)],ch1[a1]));
			a2= inc(a2,n);
			v= rot(v,g2);
			w= rot(w,g2);
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
