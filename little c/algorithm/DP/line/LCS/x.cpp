#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 3001;
int f[maxn][maxn],a[maxn],b[maxn];
int i,j,n,m;
void print(int i,int j){
	if (!i || !j) return;
	if (a[i]==b[j]){
		print(i-1,j-1);
		printf("%d ",a[i]);
	}else if (f[i-1][j]==f[i][j]) print(i-1,j);
	else print(i,j-1);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i= 1;i<=m;i++)
		scanf("%d",&b[i]);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			if (a[i]==b[j])
				f[i][j]= f[i-1][j-1]+1;
			else f[i][j]= max(f[i-1][j],f[i][j-1]);
	printf("%d\n",f[n][m]);
	print(n,m);
	return 0;
}
