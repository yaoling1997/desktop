#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 6e4,maxm= 2e6;
int g[maxm];
int a[maxn],L[maxn],R[maxn],dp[maxn],ans[maxn];
int n,m,i,j,k;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=1e6;i++)
		g[i]= g[i-1]^i;
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i= 1;i<=m;i++)
		scanf("%d%d",&L[i], &R[i]);
	for (i= 1;i<=n;i++){
		dp[i-1]= 0;
		for (j= i;j<=n;j++){
			dp[j]= g[max(a[i],a[j])]^g[min(a[i],a[j])-1];
			dp[j]= max(dp[j],dp[j-1]);
		}
		for (j= 1;j<=m;j++)
			if (L[j]<=i)
				ans[j]= max(ans[j],dp[R[j]]);
	}
	for (i= 1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
