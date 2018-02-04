#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-8,PI= acos(-1);
const int maxn= 200;
struct point{
	double x,y;
};
typedef point vec;
point ans[maxn];
point p,q;
vec v;
int n,n1,n2,i,j;
double x,y,xx,yy,wai,nei,tot,a,b,c;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
bool operator <(vec a,vec b){
	return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);
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
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &n1, &n2);
	scanf("%lf%lf%lf%lf",&x, &y, &xx, &yy);
	p= (point){x,y};
	q= (point){xx,yy};
	if (n1>n2){
		swap(n1,n2);
		swap(p,q);
	}
	wai= 2*PI/n;
	nei= PI-wai;
	ans[1]= p;
	v= q-p;
	if (n1+1==n2);
	else if (n1+2==n2){
		a= (PI-nei)/2;
		x= sin(a)*length(v)/sin(nei);
		v= v/length(v);
		v= x*v;
		v= rot(v,a);
	}else {
		int N= n2-n1+1;
		a= ((N-2)*PI-(N-2)*nei)/2;
		b= ((N-3)*PI-(N-3)*nei)/2;
		c= a-b;
		x= length(v)/sin(nei-b)*sin(c);
		v= v/length(v);
		v= x*v;
		v= rot(v,a);
	}
	for (i= 2;i<=n;i++){
		p= p+v;
		ans[i]= p;
		v= rot(v,-wai);
	}	
	for (i= n-n1+2;i<=n;i++)
		printf("%.6lf %.6lf\n",ans[i].x, ans[i].y);
	for (i= 1;i<=n-n1+1;i++)
		printf("%.6lf %.6lf\n",ans[i].x, ans[i].y);
	return 0;
}
