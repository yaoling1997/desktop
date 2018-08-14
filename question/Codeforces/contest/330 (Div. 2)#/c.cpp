#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 3e5,oo= 2e9;
int a[maxn];
int n,i,x,y,z,ans,len;
int main()
{
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	len= n/2-1;
	ans= oo;
	for (i= 1;i+len+1<=n;i++)
		ans= min(ans,a[i+len+1]-a[i]);
	printf("%d",ans);
	return 0;
}
