#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5,maxm= 1e6+1e5,oo= 1e9;
char s[maxn];
int a[30][maxn],dp[30][maxm],c[maxn],d[30];
int n,m,i,j,ans,x,y,z,mask,p,f,q,now,k;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	d[0]= 1;
	for (i= 1;i<=25;i++)
		d[i]= d[i-1]*2;
	for (i= 1;i<=n;i++){
		scanf("%s",s+1);
		for (j= 1;j<=m;j++){
			a[i][j]= s[j]-'0';
			c[j]+= a[i][j];
		}
	}
	for (i= 1;i<=m;i++){
		x= 0;
		for (j= n;j>0;j--)
			x= x*2+a[j][i];
		dp[0][x]++;
	}
	for (mask= 0;mask<d[n];mask++){
		for (p= 0;p<n;p++)
			dp[1][mask]+= dp[0][mask^d[p]];
		dp[1][mask]/= 1;
	}
	for (k= 2;k<=n;k++)
		for (mask= 0;mask<d[n];mask++){
			dp[k][mask]= (k-2-n)*dp[k-2][mask];
			for (p= 0;p<n;p++)
				dp[k][mask]+= dp[k-1][mask^d[p]];
			dp[k][mask]/= k;
		}
	ans= oo;
	for (mask= 0;mask<d[n];mask++){
		now= 0;
		for (k= 0;k<=n;k++)
			now+= min(k,n-k)*dp[k][mask];
		ans= min(ans,now);
	}
	printf("%d",ans);
	return 0;
}
