#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
const int maxn= 3e5;
int a[maxn];
int n,i,j,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i= 1;i<=n;i++)
		for (j= i+1;j<=n;j++)
			if (a[i]+a[j]==0)
				ans++;
	printf("%d",ans);
	return 0;
}
