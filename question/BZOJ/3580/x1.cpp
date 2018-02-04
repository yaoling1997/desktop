#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 3001;
int n,K,i,j;
int a[maxn];
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d %d",&n, &K);
	for (i= 1;i<=n;i++) scanf("%d",&a[i]);
	for (i= 1;i<n;i++)
		for (j= 1;j<=n-i;j++)
			if (a[j]>a[j+1]){
				if (K==0) goto pn;
				swap(a[j],a[j+1]);
				K--;
			}
 pn:if (K==0)
		for (i= 1;i<=n;i++) printf("%d ",a[i]);
	else printf("Impossible!");
	return 0;
}
