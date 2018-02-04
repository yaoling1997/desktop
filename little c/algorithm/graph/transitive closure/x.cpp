#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 1001;
int a[maxn][maxn];
int i,j,k,n,m,x,y;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++)
		a[i][i]= 1;
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		a[x][y]= 1;
	}
	for (k= 1;k<=n;k++)
		for (i= 1;i<=n;i++)
			if (i!=k)
				for (j= 1;j<=n;j++)
					if (i!=j && k!=j)
						a[i][j]= a[i][j] || (a[i][k] && a[k][j]);
	scanf("%d",&m);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		if (a[x][y]) printf("yes!\n");
	}
	return 0;
}
