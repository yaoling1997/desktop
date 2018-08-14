#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e2;
int a[maxn];
int n,m,K,i,j,k,ans,x,y;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &m, &K);
	for (i= 1;i<=K;i++) scanf("%d",&a[i]);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++){
			scanf("%d",&x);
			for (k= 1;k<=K;k++)
				if (a[k]==x) break;
			ans+= k;
			for (y= k;y>1;y--)
				a[y]= a[y-1];
			a[1]= x;
		}
	printf("%d\n",ans);
	return 0;
}