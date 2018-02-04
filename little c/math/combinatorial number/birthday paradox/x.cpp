#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,i;
double ans;
double birthday(int n,int m){
	double ans= 1;
	for (i= 1;i<=n;i++) ans= ans/m*(m-i+1);
	return 1-ans;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	ans= birthday(n,m);
	printf("%.4lf",ans);
	return 0;
}
