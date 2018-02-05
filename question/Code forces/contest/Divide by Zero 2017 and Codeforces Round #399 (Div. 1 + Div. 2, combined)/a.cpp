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
int n,i,Min,Max,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	Min= 2e9;
	Max= -2e9;
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		Min= min(Min,a[i]);
		Max= max(Max,a[i]);
	}
	for (i= 1;i<=n;i++)
		if (Min<a[i]&&a[i]<Max){
			ans++;
		}
	printf("%d",ans);
	return 0;
}