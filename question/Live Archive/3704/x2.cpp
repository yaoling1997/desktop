#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn= 300;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int i,j,n,k;
int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			scanf("%d",&a[i][j]);
	memcpy(b,a,sizeof(a));
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			for (k= 1;k<=n;k++)
				c[i][j]+= a[i][k]*b[k][j];
	for (i= 1;i<=n;i++){
		for (j= 1;j<=n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;
}
