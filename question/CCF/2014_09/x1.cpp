#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
const int maxn= 1e4;
int a[maxn];
int n,i,j,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		for (j= 1;j<i;j++)
			if (abs(a[i]-a[j])==1)
				ans++;
	}
	printf("%d",ans);
	return 0;
}

