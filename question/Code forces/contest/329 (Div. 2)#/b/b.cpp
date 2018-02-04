#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 3e5;
struct node{
	double x,y;
}p1,p2;
node a[maxn];
int n,i,j;
double x1,x2,Y1,Y2,x,y,now;
void count(double k,double b,double &Y1,double &Y2){
	Y1= k*x1+b;
	Y2= k*x2+b;
}
bool cmp(node a,node b){
	return a.x<b.x||(fabs(a.x-b.x) < 1e-8 && a.y<b.y);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	scanf("%lf%lf",&x1, &x2);
	for (i= 1;i<=n;i++){
		scanf("%lf%lf",&x, &y);
		count(x,y,Y1,Y2);
		a[i]= (node){Y1,Y2};
	}
	sort(a+1,a+n+1,cmp);
	now= a[1].y;
	for (i= 2;i<=n;i++){
		if (fabs(a[i].y-now)<1e-8) continue;
		if ((fabs(a[i].x-a[i-1].x)>1e-8)&&a[i].y<now){
			printf("YES\n");
			return 0;
		}else now= max(now,a[i].y);
	}
	printf("NO\n");
	return 0;
}
