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
point p[maxn],ch[maxn];
vec v1,v2,v3,v4;
int n,i,a1,a2,a3,a4;
double ans,g1,g3,po;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
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
double dist1(point a,point b,point p){return fabs(cj(b-a,p-a)/length(b-a));}
double area(){
	return dist1(ch[a1],ch[a1]+v1,ch[a3])*dist1(ch[a2],ch[a2]+v2,ch[a4]);
}
bool cmp(vec a,vec b){return a<b;}
int inc(int a){
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
void rotate(double r){
	v1= rot(v1,r);
	v2= rot(v2,r);
	v3= rot(v3,r);
	v4= rot(v4,r);
	while (cj(v2,ch[inc(a2)]-ch[a2])<=0) a2= inc(a2);
	while (cj(v4,ch[inc(a4)]-ch[a4])<=0) a4= inc(a4);
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
	scanf("%d\n",&n);
	scan(p,ch,n);
	for (i= 1;i<=n;i++){
		if (a1==0 || ch[a1].x>ch[i].x) a1= i;
		if (a2==0 || ch[a2].y>ch[i].y) a2= i;
		if (a3==0 || ch[a3].x<ch[i].x) a3= i;
		if (a4==0 || ch[a4].y<ch[i].y) a4= i;
	}
	v1.y= -1;v2.x= 1;v3.y= 1;v4.x= -1;
	ans= oo;
	while (po<3.4415){
		g1= angle(v1,ch[inc(a1)]-ch[a1]);
		g3= angle(v3,ch[inc(a3)]-ch[a3]);
		po+= min(g1,g3);
		if (fabs(g1-g3)<eps){
			rotate(g1);
			a1= inc(a1);
			a3= inc(a3);
			ans= min(ans,area());
		}else if (g1<g3){
			rotate(g1);
			a1= inc(a1);
			ans= min(ans,area());
		}else {
			rotate(g3);
			a3= inc(a3);
			ans= min(ans,area());
		}
	}
	printf("%.2lf",ans);
	return 0;
}
