#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const double eps= 1e-8,oo= 1e8;
struct point{
	double x,y;
};
typedef point vec;
struct circle{
	point c;
	double r;
	point getpoint(double a){
		return (point){c.x+r*cos(a),c.y+r*sin(a)};
	}
};
struct node{
	int k;
	double x,y,a,b;
	double count(double x){
		if (k) return sqrt(b*b-(x-a)*(x-a));
		else return a*x+b;
	}
};

const int maxn= 3001;
vector<point> sol;
circle C[maxn];
node a[maxn];
double h[maxn],r[maxn];
double alpha,ans,cnt,L,R;
int n,i,tot;

int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);}
bool operator ==(vec a,vec b){return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dj(a,a));}
double polarAngle(vec a){return atan2(a.y,a.x);}
bool cmp(node a,node b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int tangents(circle c1,circle c2){
	sol.clear();
	if (c1.r<c2.r) swap(c1,c2);
	point o1= c1.c,o2= c2.c;
	double r1= c1.r,r2= c2.r,d= length(o1-o2);
	if (!dcmp(d)) return 0;
	double da= acos((r1-r2)/d),base= polarAngle(o2-o1);
	sol.push_back(c1.getpoint(da+base));
	sol.push_back(c2.getpoint(da+base));
	return 1;
}
void prepare(){
	a[++tot]= (node){1,-C[1].r,C[1].r,0,C[1].r};
	for (int i= 2;i<=n+1;i++){
		a[++tot]= (node){1,C[i].c.x-C[i].r,C[i].c.x+C[i].r,C[i].c.x,C[i].r};
		if (tangents(C[i-1],C[i])){
			point p= sol[0],q= sol[1];
			p.y= fabs(p.y);q.y= fabs(q.y);
			if (q<p) swap(p,q);
			a[++tot]= (node){0,p.x,q.x,(q.y-p.y)/(q.x-p.x),p.y-p.x*(q.y-p.y)/(q.x-p.x)};
		}		
	}
	sort(a+1,a+tot+1,cmp);
}
double F(double x){
	int i;double re= -oo;
	for (i= 1;i<=tot;i++)
		if (dcmp(x-a[i].x)>=0&&dcmp(x-a[i].y)<=0)
			re= max(re,a[i].count(x));
	return re;
}
double simpson(double a,double b,double l,double m,double r){
	return (l+4*m+r)*(b-a)/6;
}
double asr(double a,double b,double l,double m,double r,double eps,double A){
	double c= (a+b)/2,m1= F((a+c)/2),m2= F((c+b)/2);
	double L= simpson(a,c,l,m1,m),R= simpson(c,b,m,m2,r);
	if (fabs(L+R-A)<eps) return L+R;
	return asr(a,c,l,m1,m,eps,L)+asr(c,b,m,m2,r,eps,R);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %lf",&n, &alpha);
	for (i= 0;i<=n;i++)
		scanf("%lf",&h[i]);
	for (i= 1;i<=n;i++)
		scanf("%lf",&r[i]);
	L= oo;R= -oo;
	for (i= 1;i<=n+1;i++){
		C[i].c= (point){cnt,0};
		C[i].r= r[i];
		cnt+= h[i]/tan(alpha);
		L= min(L,C[i].c.x-r[i]);
		R= max(R,C[i].c.x+r[i]);
	}
	prepare();
	double fl,fr,fm;
	fl= F(L);fr= F(R);fm= F((L+R)/2);
	ans= 2*asr(L,R,fl,fm,fr,1e-6,simpson(L,R,fl,fm,fr));
	printf("%.2lf",ans);
	return 0;
}
