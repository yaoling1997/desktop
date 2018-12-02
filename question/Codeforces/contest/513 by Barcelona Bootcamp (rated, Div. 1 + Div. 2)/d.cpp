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
int a[maxn],b[maxn];
int n;
ll ans=0;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",a+i,b+i);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
		ans+=max(a[i],b[i]);
	ans+=n;
	printf("%I64d",ans);
	return 0;
}
