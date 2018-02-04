#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-8;
const int maxn= 3e5;
struct point{
	double x,y;
};
typedef point vec;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
bool operator <(vec a,vec b){
	return dcmp(a.x-b.x)<0||
		(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);
}
bool operator ==(vec a,vec b){
	return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);
}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
point jd(point p,vec v,point q,vec w){
	vec u= p-q;
	double t= cj(w,u)/cj(v,w);
	return p+t*v;
}
bool xj(point a,point b,point p,point q){
	double x1= cj(q-p,a-p),x2= cj(q-p,b-p);
	return dcmp(x1*x2)<=0;
}
bool cmp(point a,point b){
	return a<b;
}
point p[maxn],ch[maxn];
point P,O,Q;
double x,y,_p,_q,mx,my;
int n,i,j,m;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%lf%lf",&n, &_p, &_q);
	P= (point){_p,_q};
	for (i= 1;i<=n;i++){
		scanf("%lf%lf",&x, &y);
		p[i]= (point){x,y};
		mx= max(mx,x);
		my= max(my,y);
	}
	p[++n]= (point){0,0};
	p[++n]= (point){mx,0};
	p[++n]= (point){0,my};
	sort(p+1,p+n+1,cmp);
	for (i= 1;i<=n;i++){
		while (m>1&&dcmp(cj(ch[m]-ch[m-1],p[i]-ch[m-1]))<=0) m--;
		ch[++m]= p[i];
	}
	int k= m;
	for (i= n-1;i>0;i--){
		while (m>k&&dcmp(cj(ch[m]-ch[m-1],p[i]-ch[m-1]))<=0) m--;
		ch[++m]= p[i];
	}
	for (i= 1;i<m;i++){
		if (ch[i]==O||ch[i+1]==O) continue;
		if (xj(ch[i],ch[i+1],O,P)){
			Q= jd(ch[i],ch[i+1]-ch[i],O,P-O);
			break;
		}
	}
	printf("%.10lf",P.y/Q.y);
	return 0;
}
