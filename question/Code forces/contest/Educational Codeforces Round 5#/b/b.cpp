#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int a[500][500];
int n,m,i,j,ans,now;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		now= 2e9;
		for (j= 1;j<=m;j++){
			scanf("%d",&a[i][j]);
			now= min(now,a[i][j]);
		}
		ans= max(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}
