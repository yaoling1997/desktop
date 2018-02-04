#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e3;
int a[5][maxn],b[maxn],c[maxn];
int sum[5][maxn];
int n,i,j,ans;
int main()
{
	scanf("%d",&n);
	for (i= 1;i<=2;i++)
		for (j= 1;j<n;j++)
			scanf("%d",&a[i][j]);
	for (i= 1;i<=n;i++)
		scanf("%d",&b[i]);
	for (i= 2;i<=n;i++)
		sum[1][i]= sum[1][i-1]+a[1][i-1];
	for (i= n-1;i>0;i--)
		sum[2][i]= sum[2][i+1]+a[2][i];
	for (i= 1;i<=n;i++)
		c[i]= sum[1][i]+sum[2][i]+b[i];
	sort(c+1,c+n+1);
	printf("%d",c[1]+c[2]);
	return 0;
}
