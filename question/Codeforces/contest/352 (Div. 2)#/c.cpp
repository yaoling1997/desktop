#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const double eps= 1e-12,oo= 1e18;
const int maxn= 5e5;
struct point{
	double x,y;
}a,b,t,P[maxn];
typedef point vec;
double L[maxn];
int sta[10],stb[10];
int n,i,j,la,lb;
double ans,x,y,sum;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){
	return sqrt(dj(a,a));
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%lf%lf",&a.x,&a.y);
	scanf("%lf%lf",&b.x,&b.y);
	scanf("%lf%lf",&t.x,&t.y);
	scanf("%d",&n);
	ans= oo;
	for (i= 1;i<=n;i++){
		scanf("%lf%lf",&P[i].x, &P[i].y);
		L[i]= length(P[i]-t);
		sum+= L[i]*2;
	}
	if (n==1){
		ans= min(length(P[1]-a),length(P[1]-b))+L[1];
	}else {
		for (i= 1;i<=n;i++){
			ans= min(ans,sum-L[i]+length(P[i]-a));
			ans= min(ans,sum-L[i]+length(P[i]-b));			
			if (la<2){
				sta[++la]= i;
				if (la==2){
					if (-L[sta[1]]+length(P[sta[1]]-a)>-L[sta[2]]+length(P[sta[2]]-a))
						swap(sta[1],sta[2]);					
				}
			}else {
				j= sta[la];
				if (-L[j]+length(P[j]-a)>-L[i]+length(P[i]-a)){
					sta[la]= i;
					if (-L[sta[1]]+length(P[sta[1]]-a)>-L[sta[2]]+length(P[sta[2]]-a))
						swap(sta[1],sta[2]);
				}
			}
			if (lb<2){
				stb[++lb]= i;
				if (lb==2){
					if (-L[stb[1]]+length(P[stb[1]]-b)>-L[stb[2]]+length(P[stb[2]]-b))
						swap(stb[1],stb[2]);					
				}
			}else {
				j= stb[lb];
				if (-L[j]+length(P[j]-b)>-L[i]+length(P[i]-b)){
					stb[lb]= i;
					if (-L[stb[1]]+length(P[stb[1]]-b)>-L[stb[2]]+length(P[stb[2]]-b))
						swap(stb[1],stb[2]);
				}				
			}
		}
		if (sta[1]!=stb[1]){
			i= sta[1];
			j= stb[1];
			x= sum-L[i]+length(P[i]-a)-L[j]+length(P[j]-b);
			ans= min(ans,x);
		}else {
			i= sta[1];
			j= stb[2];
			x= sum-L[i]+length(P[i]-a)-L[j]+length(P[j]-b);
			ans= min(ans,x);
			i= sta[2];
			j= stb[1];
			x= sum-L[i]+length(P[i]-a)-L[j]+length(P[j]-b);
			ans= min(ans,x);						
		}
	}printf("%.12lf",ans);
	return 0;
}