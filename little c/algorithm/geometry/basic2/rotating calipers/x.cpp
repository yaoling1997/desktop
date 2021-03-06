#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps= 1e-8,rad= 0.333;
const int maxn= 3001,oo= 99999999;
struct point{
	double x,y;
};
typedef point vec;
point p[maxn],ch[maxn],v,w;
int i,n,m,k,a1,a2,b1,b2;
double po,g1,g2,ans;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return (a.x<b.x) || (a.x==b.x &&a.y<b.y);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dj(a,a));}
vec rot(vec a,double r){vec c;c.x= a.x*cos(r)-a.y*sin(r);c.y= a.x*sin(r)+a.y*cos(r);return c;}
bool cmp(vec a,vec b){return a<b;}
double angle (vec a,vec b){return acos(dj(a,b)/length(a)/length(b));}
void com(int a,int b){
	double g= length(ch[a]-ch[b]);
	if (g>ans){
		ans= g;
		b1= a;b2= b;
	}
}
int inc(int a){a++;if (a>m) a-= m;return a;}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++){
		scanf("%lf %lf\n",&p[i].x,&p[i].y);
		p[i]= rot(p[i],rad);
	}
	sort(p+1,p+n+1,cmp);
	for (i= 1;i<=n;i++){
		while (m>1 && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<=0) m--;
		ch[++m]= p[i];
	}
	k= m;
	for (i= n-1;i>0;i--){
		while (m>k && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<=0) m--;
		ch[++m]= p[i];
	}
	if (n>1) m--;
	for (i= 1;i<=m;i++){
		if (a1==0 || (ch[a1].x>ch[i].x)) a1= i;
		if (a2==0 || (ch[a2].x<ch[i].x)) a2= i; 
	}
	v.y= -1;w.y= 1;b1= a1;b2= a2;ans= length(ch[b2]-ch[b1]);
	while (po<=3.3415926){
		g1= angle(v,ch[inc(a1)]-ch[a1]);
		g2= angle(w,ch[inc(a2)]-ch[a2]);
		po+= min(g1,g2);
		if (fabs(g1-g2)<eps){
			com(a1,inc(a2));
			com(inc(a1),a2);
			com(inc(a1),inc(a2));
			v= rot(v,g1);
			w= rot(w,g1);
			a1= inc(a1);a2= inc(a2);
		}
		else if (g1<g2){
			com(inc(a1),a2);
			v= rot(v,g1);
			w= rot(w,g1);
			a1= inc(a1);
		}
		else {
			com(a1,inc(a2));
			v= rot(v,g2);
			w= rot(w,g2);
			a2= inc(a2);
		}
	}
	ch[b1]= rot(ch[b1],-rad);
	ch[b2]= rot(ch[b2],-rad);
	if (!dcmp(ch[b1].x)) ch[b1].x= 0;
	if (!dcmp(ch[b1].y)) ch[b1].y= 0;
	if (!dcmp(ch[b2].x)) ch[b2].x= 0;
	if (!dcmp(ch[b2].y)) ch[b2].y= 0;
	printf("%.2lf %.2lf\n",ch[b1].x,ch[b1].y);
	printf("%.2lf %.2lf\n",ch[b2].x,ch[b2].y);
	printf("%.2lf\n",ans);
	return 0;
}
