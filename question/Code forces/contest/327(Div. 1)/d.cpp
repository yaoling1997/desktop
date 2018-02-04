#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 160,oo= 1e9;
int f[maxn][maxn*maxn],q[maxn],g[maxn];
int i,j,k,p,n,K,s,ans,M;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &K, &s);
	for (i= 1;i<=n;i++){
		scanf("%d",&q[i]);
		g[i]= q[i];
	}
	sort(g+1,g+n+1);
	if (s>n*(n-1)/2){
		for (i= 1;i<=K;i++)
			ans+= g[i];
		printf("%d\n",ans);
	}else {
		M= K*(K+1)/2+s;
		ans= oo;
		for (i= 0;i<=n;i++)
			for (j= 0;j<=M;j++)
				f[i][j]= oo;
		f[0][0]= 0;
		for (i= 1;i<=n;i++)
			for (j= min(i,K);j>=1;j--)
				for (p= M;p>=i;p--)
					f[j][p]= min(f[j][p],f[j-1][p-i]+q[i]);
		for (p= 1;p<=M;p++)
			ans= min(ans,f[K][p]);
		printf("%d\n",ans);
	}return 0;
}
