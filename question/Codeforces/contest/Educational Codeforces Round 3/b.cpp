#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn= 100;
int a[maxn];
int n,m,i,j,x;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	int ans= 0;
	for (i= 1;i<=m;i++)
		for (j= i+1;j<=m;j++)
			ans+= a[i]*a[j];
	printf("%d\n",ans);
	return 0;
}
