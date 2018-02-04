#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 3001;
int c[maxn],n,k,i,x;
int main()
{
	scanf("%d%d",&n, &k);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		c[x]++;
	}
	int final= n/k,ans= 0;
	for (i= 1;i<=k;i++)
		ans+= max(c[i]-final,0);
	printf("%d",ans);
	return 0;
}
