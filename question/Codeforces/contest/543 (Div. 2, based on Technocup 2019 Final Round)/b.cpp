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
int n;
int a[1010],b[maxn];
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);		
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			b[a[i]+a[j]]++;
	int ans=0;
	for (int i=1;i<=2e5;i++)
		ans=max(ans,b[i]);
	printf("%d",ans);
	return 0;
}
