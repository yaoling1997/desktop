#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int n,m,ans,i,j,x,y;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++){
			scanf("%d%d",&x, &y);
			if (x+y>0) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
