#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 600;
char s[maxn][maxn];
ll fh[maxn][maxn],fv[maxn][maxn];
ll n,m,i,j,ans,q;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld%lld",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++){
			fh[i][j]= fh[i][j-1];
			if (s[i][j-1]=='.'&&s[i][j]=='.')
				fh[i][j]++;
		}
	}
	for (i= 1;i<=m;i++)
		for (j= 1;j<=n;j++){
			fv[j][i]= fv[j-1][i];
			if (s[j-1][i]=='.'&&s[j][i]=='.')
				fv[j][i]++;
		}
	scanf("%lld",&q);
	for (ll qq= 1;qq<=q;qq++){
		ll r1,r2,c1,c2;
		scanf("%lld%lld%lld%lld",&r1, &c1, &r2, &c2);
		ans= 0;
		for (i= r1;i<=r2;i++)
			ans+= fh[i][c2]-fh[i][c1];
		for (i= c1;i<=c2;i++)
			ans+= fv[r2][i]-fv[r1][i];
		printf("%lld\n",ans);
	}return 0;
}
