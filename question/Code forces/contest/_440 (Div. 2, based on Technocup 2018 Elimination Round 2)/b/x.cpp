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
int a[maxn];
int n,k;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &k);
	for (int i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	if (k>=3){
		int ans= -1e9-1;
		for (int i= 1;i<=n;i++)
			ans= max(ans,a[i]);
		printf("%d",ans);
	}else if (k==2){
		int ans= max(a[1],a[n]);
		printf("%d",ans);
	}else {
		int ans= 1e9+1;
		for (int i= 1;i<=n;i++)
			ans= min(ans,a[i]);
		printf("%d",ans);		
	}
	return 0;
}
