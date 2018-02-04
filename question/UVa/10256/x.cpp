#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn= 3001;
const double eps= 1e-8,rad= 0.00333;
struct point{
	double x,y;
};
typedef point vec;
int n,m,m1,m2,i,j;
point p1[maxn],p2[maxn],ch1[maxn],ch2[maxn];
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator ==(vec a,vec b){return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<0 || (!dcmp(a.x-b.x) && dcmp(a.y-b.y)<0);}
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
void convexhull(point *p,point *ch,int n,int &m){
	m= 0;
	for (int i= 1;i<=n;i++){
		while (m>1 && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<0) m--;
		ch[++m]= p[i];
	}
	int k= m;
	for (int i= n-1;i>0;i--){
		while (m>k && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<0) m--;
		ch[++m]= p[i];
	}
}
bool ipos(point a,point b,point p){
	if (!dcmp(cj(b-a,p-a))){
		if (b<a) swap(a,b);
		if (dcmp(p.x-a.x)>=0 && dcmp(p.x-b.x)<=0) return 1;
		return 0;
	}return 0;
}
bool xj(point a1,point a2,point b1,point b2){
	if (ipos(a1,a2,b1)||ipos(a1,a2,b2)|ipos(b1,b2,a1)||ipos(b1,b2,a2)) return 1;
	double x1= cj(a2-a1,b1-a1),x2= cj(a2-a1,b2-a1);
	double y1= cj(b2-b1,a1-b1),y2= cj(b2-b1,a2-b1);
	return x1*x2<0 && y1*y2<0;
}
bool cmp(point a,point b){return a<b;}
int ipip(point *pn,int n,point p){
	int wn= 0;
	double k,d1,d2;
	pn[n+1]= pn[1];
	for (int i= 1;i<=n;i++){
		if (ipos(pn[i],pn[i+1],p)) return -1;
		k= cj(pn[i+1]-pn[i],p-pn[i]);
		d1= pn[i].y-p.y;
		d2= pn[i+1].y-p.y;
		if (k>0 && d1<=0 && d2>0) wn++;
		if (k<0 && d2<=0 && d1>0) wn--;
	}
	pn[n+1]= pn[0];
	return wn;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d %d",&n, &m)!=EOF){
		if (n==0 && m==0) break;
		for (i= 1;i<=n;i++){
			scanf("%lf %lf",&p1[i].x, &p1[i].y);
			p1[i]= rot(p1[i],rad);
		}
		sort(p1+1,p1+n+1,cmp);
		convexhull(p1,ch1,n,m1);
		for (i= 1;i<=m;i++){
			scanf("%lf %lf",&p2[i].x, &p2[i].y);
			p2[i]= rot(p2[i],rad);
		}
		sort(p2+1,p2+m+1,cmp);
		convexhull(p2,ch2,m,m2);
		int bl= 1;
		for (i= 1;i<=m1-1;i++){
			for (j= 1;j<=m2-1;j++)
				if (xj(ch1[i],ch1[i+1],ch2[j],ch2[j+1])){
					bl= 0;
					break;
				}
			if (!bl) break;
		}
		if (bl){
			int re= ipip(ch1,m1-1,p2[1]);
			if (re) bl= 0;
			if (bl){
				re= ipip(ch2,m2-1,p1[1]);
				if (re) bl= 0;
			}
		}
		if (bl) printf("Yes\n");
		else printf("No\n");
	}
}
