#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 3001;
int a[maxn];
int i,j,n;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i= 1;i<=n;i++)
		for (j= i+1;j<=n;j++)
			if (a[i]>a[j]) swap(a[i],a[j]);
	for (i= 1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
