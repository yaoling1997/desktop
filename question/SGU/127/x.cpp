#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 1e4;
int a[maxn];
int K,i,j,ans,n,now;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&K, &n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]/= 1000;
	}
	sort(a+1,a+n+1);
	ans= 3;
	now= 1;
	for (i= 2;i<=n;i++)
		if (a[i]==a[i-1]){
			now++;
			if (now>K){
				now-= K;
				ans++;
			}
		}else {
			ans++;
			now= 1;
		}
	printf("%d",ans);
	return 0;
}
