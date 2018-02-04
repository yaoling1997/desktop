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
		for (j= n;j>i;j--)
			if (a[j]<a[j-1])
				swap(a[j],a[j-1]);
	for (i= 1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
