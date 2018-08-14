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
int a[maxn][maxn];
int n,k,i,j,now,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &k);
	for (i= 1;i<=n;i++)
		for (j= 1;j<k;j++)
			a[i][j]= ++now;
	for (i= 1;i<=n;i++)
		for (j= k;j<=n;j++)
			a[i][j]= ++now;
	for (i= 1;i<=n;i++)
		ans+= a[i][k];
	printf("%d\n",ans);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			printf("%d%c",a[i][j],j<n?' ':'\n');
	return 0;
}
