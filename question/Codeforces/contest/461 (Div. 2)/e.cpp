#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 1e3+10,maxm=1e4+10;
ll c[maxn],cost[maxn],f[maxn][maxm];
int n,W,B,X,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d%d",&n, &W, &B, &X);
	memset(f,-1,sizeof(f));
	f[0][0]=W;
	for (int i=1;i<=n;i++)
		scanf("%I64d",&c[i]);
	for (int i=1;i<=n;i++)
		scanf("%I64d",&cost[i]);
	for (int i=1;i<=n;i++)
		for (int j=0;j<maxm;j++)
			for (int k=0;k<=c[i]&&k<=j;k++){
				if (f[i-1][j-k]==-1)
					continue;
				if (f[i-1][j-k]<(ll)k*cost[i])
					continue;
				f[i][j]=max(f[i][j],min(f[i-1][j-k]-(ll)k*cost[i]+X,W+(ll)j*B));
			}
	for (int i=0;i<maxm;i++)
		if (f[n][i]!=-1)
			ans=i;
	printf("%d",ans);
	return 0;
}
