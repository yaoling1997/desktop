#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 2e5;
int a[maxn],p[maxn];
int n,i,ans,j,k;
int main()
{
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&a[i], &p[i]);
		a[i]+= a[i-1];
	}
	j= 1;
	for (i= 2;i<=n;i++)
		if (p[i]<p[j]){
			ans+= (a[i-1]-a[j-1])*p[j];
			j= i;
		}
	ans+= (a[n]-a[j-1])*p[j];
	printf("%d\n",ans);
	return 0;
}
