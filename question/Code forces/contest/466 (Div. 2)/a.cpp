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
int ans=1000,n,d;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &d);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int cnt=0;
	for (int i= 1;i<=n;i++){
		int now=cnt;
		for (int j=i+1;j<=n;j++)
			if (a[j]-a[i]>d){
				now+=n-j+1;
				break;
			}
		ans=min(ans,now);
		cnt++;
	}
	printf("%d",ans);
	return 0;
}
