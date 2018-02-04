#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e4;
ll d[maxn];
ll ans;
int n,m,i,j,x,y;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		d[x]++;
		d[y]++;
	}
	for (i= 1;i<=n;i++)
		ans+= d[i]*d[i];
	printf("%lld",ans);
}
