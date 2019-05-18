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
int n,ans,i,j;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);	
	ans= 0;
	for (i= 1;i<=n;i++){
		int h= a[i];
		for (j= i;j<=n;j++){
			h= min(h,a[j]);
			ans= max(ans,(j-i+1)*h);
		}
	}
	printf("%d",ans);
	return 0;
}
