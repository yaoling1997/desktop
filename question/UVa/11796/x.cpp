#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-8,oo= 1e9;
const int maxn= 100;
struct point{
	double x,y;
}a[maxn],b[maxn];
typedef point vec;
point p,q;
double lena,lenb,va,vb,x,y,Max,Min;
int I,A,B,i,j;
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
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dj(a,a));}
void init(){
	lena= lenb= 0;
}
double dl(point a,point b,point p){
	return max(length(p-a),length(p-b));
}
double dist(point a,point b,point p){
	return fabs(cj(b-a,p-a)/length(b-a));
}
double ds(point a,point b,point p){
	if (dj(b-a,p-a)<0) return length(p-a);
	if (dj(a-b,p-b)<0) return length(p-b);
	return dist(a,b,p);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&I);
	for (int T= 1;T<=I;T++){
		scanf("%d%d",&A, &B);
		init();
		for (i= 1;i<=A;i++){
			scanf("%lf%lf",&x, &y);
			a[i]= (point){x,y};
		}
		for (i= 1;i<=B;i++){
			scanf("%lf%lf",&x, &y);
			b[i]= (point){x,y};
		}
		for (i= 2;i<=A;i++)
			lena+= length(a[i]-a[i-1]);
		for (i= 2;i<=B;i++)
			lenb+= length(b[i]-b[i-1]);
		va= lena;
		vb= lenb;
		p= a[1];
		q= b[1];
		Max= Min= length(p-q);
		i= 2;
		j= 2;	   
		while (i<=A&&j<=B){
			double ta= length(a[i]-p)/va;
			double tb= length(b[j]-q)/vb;
			double t= min(ta,tb);
			vec Va= a[i]-a[i-1];
			vec Vb= b[j]-b[j-1];
			Va= Va/length(Va);
			Vb= Vb/length(Vb);
			point c= q+vb*t*Vb-va*t*Va;
			x= dl(q,c,p);
			y= ds(q,c,p);
			Max= max(Max,x);
			Min= min(Min,y);
			if (!dcmp(ta-tb)){
				p= a[i];
				q= b[j];
				i++;
				j++;
			}else if (dcmp(ta-tb)<0){
				p= a[i];
				i++;
				q= q+vb*ta*Vb;
			}else {
				q= b[j];
				j++;
				p= p+va*tb*Va;
			}
		}
		printf("Case %d: %.0lf\n",T, Max-Min);
	}return 0;
}
