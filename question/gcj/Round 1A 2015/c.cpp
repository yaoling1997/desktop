#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<ctime>
#define ll long long
#define ld long double
using namespace std;
const double eps= 1e-8;
const int maxn= 2e4,oo= 1e9;
struct point{
	double x,y;
}P[maxn],ch[maxn];
typedef point vec;
double a[maxn];
int ans[maxn],sh[maxn];
point O;
double x,y;
int T,n,i,j;
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
bool operator <(vec a,vec b){
	return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);
}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double polarAngle(vec a){
	return atan2(a.y,a.x);
}
bool cmp(int x,int y){
	return a[x]<a[y];
}
int getAns(int o){
	O= P[o];
	int i,re= oo,m= 0;
	for (i= 1;i<=n;i++){
		if (i==o) continue;
		ch[++m]= P[i];
	}
	for (i= 1;i<=n-1;i++){
		a[i]= polarAngle(ch[i]-O);
		sh[i]= i;
	}
	sort(sh+1,sh+m+1,cmp);
	for (i= 1;i<=n-1;i++)
		sh[++m]= sh[i];
	int j= 0;
	for (i= 1;i<=n-1;i++){
		j= max(j,i+1);
		while (j<=m&&dcmp(cj(ch[sh[i]]-O,ch[sh[j]]-O))>0) j++;
		re= min(re,j-i-1);
	}return re;
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	/*int beginT= clock();				
	for (i= 1;i<=1e7;i++)
		polarAngle((point){1982138,2138932});
		int endT= clock();
	printf("%.2lf",(endT-beginT)/1000.0);
	return 0;	*/
	for (int t= 1;t<=T;t++){
		printf("Case #%d:\n",t);
		scanf("%d",&n);
		for (i= 1;i<=n;i++){
			scanf("%lf%lf",&x, &y);
			P[i]= (point){x,y};
		}
		for (i= 1;i<=n;i++){
			ans[i]= getAns(i);
		}
		if (n==1) ans[1]= 0;
		for (i= 1;i<=n;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
