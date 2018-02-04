#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 1e6;
int bfs[maxn],dfs[maxn],posb[maxn],posd[maxn];
int max1[maxn],max2[maxn],use[maxn];
double ans;
int i,n;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&dfs[i]);
		posd[dfs[i]]= i;
	}
	for (i= 1;i<=n;i++){
		scanf("%d",&bfs[i]);
		posb[bfs[i]]= i;
	}
	for (i= 1;i<=n;i++){
		max1[i]= max(max1[i-1],posb[dfs[i]]);
		max2[i]= max(max2[i-1],posd[bfs[i]]);
	}
	ans= 2;
	for (i= 3;i<=n;i++){
		if (posd[bfs[i-1]]>posd[bfs[i]]) ans++;
		else if (posd[bfs[i-1]]==posd[bfs[i]]-1&&
				 max1[posd[bfs[i]]]==i&&max2[posb[dfs[i]]]==posd[bfs[i]])
			use[i]= 1;
	}
	for (i= n;i>=3&&posd[bfs[i-1]]==posd[bfs[i]]-1;i--) use[i]= 1;
	for (i= 1;i<=n;i++)
		if (use[i])
			ans+= 0.5;
	printf("%.3lf\n%.3lf\n%.3lf",ans-0.001,ans,ans+0.001);
	return 0;
}
