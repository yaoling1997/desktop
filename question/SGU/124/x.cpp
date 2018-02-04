#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
const double eps= 1e-8,da= 1,oo= 1e9;
const int maxn= 5e4;
struct point{
	double x,y;
};
struct line{
	point a,b;
}L[maxn];
typedef point vec;
vector<int> V[maxn];
point P[maxn];
point p,q,o;
int vis[maxn];
int m,n,i,j,base= 10010,x,y,xx,yy,bl;
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
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double length(vec a){
	return sqrt(dj(a,a));
}
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
bool ipos(point a,point b,point p){
	if (a==p||b==p) return 1;
	return !dcmp(cj(b-a,p-a))&&dcmp(dj(p-a,p-b))<0;
}
int ipip(point *P,point p,int n){
	P[n+1]= P[1];
	int i,wn= 0;
	for (i= 1;i<=n;i++){
		if (ipos(P[i],P[i+1],p)) return oo;
		double k= cj(P[i+1]-P[i],p-P[i]);
		double d1= dcmp(p.y-P[i].y);
		double d2= dcmp(p.y-P[i+1].y);
		if (k>0&&d1>=0&&d2<0) wn++;
		if (k<0&&d2>=0&&d1<0) wn--;
	}
	return wn;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d%d%d",&x, &y, &xx, &yy);
		point a= (point){x,y};
		point b= (point){xx,yy};
		L[i]= (line){a,b};
		V[x+base].push_back(i);
		V[xx+base].push_back(i);		
	}
	scanf("%lf%lf",&o.x, &o.y);
	P[++m]= L[1].a;
	p= L[1].b;
	vis[1]= 1;
	while (!(p==P[1])){
		int u= p.x+base;
		int len= V[u].size();
		bl= 0;
		for (i= 0;i<len;i++){
			if (vis[V[u][i]]) continue;
			if (L[V[u][i]].a==p){
				q= L[V[u][i]].b;
				vis[V[u][i]]= 1;
				bl= 1;
				break;
			}else if (L[V[u][i]].b==p){
				q= L[V[u][i]].a;
				vis[V[u][i]]= 1;
				bl= 1;
				break;				
			}
		}
		if (bl)	P[++m]= p;
		else break;
		p= q;
	}
	if (m!=n){
		printf("BORDER");
		return 0;
	}
	for (i= 1;i<=m;i++)
		P[i]= rot(P[i],da);
	o= rot(o,da);
	int ans= ipip(P,o,m);
	if (ans==oo) printf("BORDER");
	else if (ans) printf("INSIDE");
	else printf("OUTSIDE");
	return 0;
}
