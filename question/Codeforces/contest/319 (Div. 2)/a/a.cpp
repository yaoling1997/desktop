#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int n,x,ans,i;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &x);
	for (i= 1;i<=n;i++)
		if (x%i==0&&x/i<=n)
			ans++;
	printf("%d\n",ans);
}
