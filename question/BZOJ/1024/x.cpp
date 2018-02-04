#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 3001,oo= 1e9;
double x,y,ans;
int n;
double dfs(double x,double y,int n){
	if (x<y) swap(x,y);
	if (n==1) return x/y;
	double r= 1.0/n,re= oo,now;
	int i;
	for (i= 1;i<n;i++){
		now= max(dfs(x*r*i,y,i),dfs(x*r*(n-i),y,n-i));
		re= min(re,now);
		now= max(dfs(x,y*r*i,i),dfs(x,y*r*(n-i),n-i));
		re= min(re,now);
	}return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lf %lf %d",&x, &y, &n);
	ans= dfs(x,y,n);
	printf("%.6lf",ans);
	return 0;
}
