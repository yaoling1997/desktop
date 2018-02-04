#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const double eps= 1e-8,oo= 1e5;
const int maxn= 30001;
struct point{
	double x,y;
};
typedef point vec;
double g[maxn];
point L[maxn][2][2];
point p1,p2,p3,p4,p,P,last;
vec v;
int n,i,j,k,z,top,cnt;
double ans;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<0 || (!dcmp(a.x-b.x) && dcmp(a.y-b.y)<0);}
bool operator ==(vec a,vec b){return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){
	return sqrt(dj(a,a));
}
point jd(point p,vec v,point q,vec w){
	vec u= p-q;
	return p+cj(w,u)/cj(v,w)*v;
}
bool os(point a,point b,point p){
	return !dcmp(cj(b-a,p-a)) && dcmp(dj(p-a,p-b))<0;
}
bool xj(point a1,point a2,point b1,point b2){
	double x1= cj(a2-a1,b1-a1),x2= cj(a2-a1,b2-a1);
	double y1= cj(b2-b1,a1-b1),y2= cj(b2-b1,a2-b1);
	return dcmp(x1*x2)<0 && dcmp(y1*y2)<0;
}
bool Xj(point a1,point a2,point b1,point b2){
	double x1= cj(a2-a1,b1-a1),x2= cj(a2-a1,b2-a1);
	double y1= cj(b2-b1,a1-b1),y2= cj(b2-b1,a2-b1);
	if (os(a1,a2,b1)||os(a1,a2,b2)||os(b1,b2,a1)||os(b1,b2,a2)) return 1;
	return dcmp(x1*x2)<0 && dcmp(y1*y2)<0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	v= (vec){0,10000};	
	while (scanf("%d",&n)!=EOF){		
		if (!n) break;
		top= ans= 0;cnt++;
		for (i= 1;i<=n;i++){
			double x,y,z;
			scanf("%lf %lf %lf",&x, &y, &z);
			z/= 2;
			L[i][0][0]= (point){x-z,0};
			L[i][0][1]= L[i][1][0]= (point){x,y};
			L[i][1][1]= (point){x+z,0};
			g[++top]= x-z;
			g[++top]= x;
			g[++top]= x+z;
		}
		for (i= 1;i<=n;i++)
			for (j= i+1;j<=n;j++)
				for (k= 0;k<=1;k++)
					for (z= 0;z<=1;z++){
						p1= L[i][k][0];p2= L[i][k][1];
						p3= L[j][z][0];p4= L[j][z][1];
						if (xj(p1,p2,p3,p4)){
							p= jd(p1,p2-p1,p3,p4-p3);
							g[++top]= p.x;
						}
					}
		sort(g+1,g+top+1);
		top= unique(g+1,g+top+1)-g-1;
		last= (point){-oo,0};
		for (i= 1;i<=top;i++){
			double y= 0;P= (point){g[i],0};
			for (j= 1;j<=n;j++)
				for (k= 0;k<=1;k++){
					p1= L[j][k][0];p2= L[j][k][1];
					if (Xj(P,P+v,p1,p2)){
						p= jd(P,v,p1,p2-p1);
						y= max(y,p.y);
					}
				}
			P.y= y;
			if (dcmp(y-last.y))
				ans+= length(P-last);
			last= P;
		}
		printf("Case %d: %.0lf\n\n",cnt, ans);
	}
	return 0;
}
