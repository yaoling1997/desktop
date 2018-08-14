#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3001;
int a[maxn];
int n,i,ans;
int main()
{
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (i= 1;i<=n;i++)
		if (a[i]==0&&(a[i-1]==0||a[i+1]==0)){			
		}else ans++;
	printf("%d",ans);
	return 0;
}
