#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
const int maxn= 3001;
struct point{
	double x,y;
};
typedef point vec;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double arean(point* P,int n){
	double area= 0;
	for (int i= 2;i<n;i++)
		area+= cj(P[i]-P[1],P[i+1]-P[1]);	
	return fabs(area)/2;
} 
point P[maxn];
int n,i,j;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++){
		scanf("%lf %lf\n",&P[i].x, &P[i].y);
	}
	printf("%.4lf",arean(P,n));
	return 0;	
}
