#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
const int maxn= 30000;
int a[maxn],b[maxn],c[maxn];
int i,j,ans,n;
int main()
{
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d %d",&a[i],&b[i]);
	for (i= 2;i<=n;i++)
		for (j= a[i]+1;j<=b[i];j++)
			c[j]= 1;
	for (i= a[1]+1;i<=b[1];i++)
		if (!c[i]) ans++;
	printf("%d",ans);
}
