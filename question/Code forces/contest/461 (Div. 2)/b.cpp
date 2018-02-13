#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int n,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++){
			int k=i^j;
			ans+= j<=k&&k<=n&&i+j>k;
		}
	printf("%d",ans);
	return 0;
}
