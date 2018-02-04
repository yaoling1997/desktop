#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 200;
vector<int> g[maxn];
int a[maxn][maxn];
int d[maxn],vis[maxn];
int n,i,j,x,y,bl;
void dfs(int o,int c){
	vis[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (a[o][v]) continue;
		a[o][v]= c;
		a[v][o]= c;
		c= 3-c;
		dfs(v,c);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		for (;;){
			scanf("%d",&x);
			if (!x) break;
			g[i].push_back(x);			
		}
	}
	for (i= 1;i<=n;i++)
		if (!vis[i]&&g[i].size()%2)
			dfs(i,1);
	for (i= 1;i<=n;i++)
		if (!vis[i])
			dfs(i,1);
	bl= 1;
	for (i= 1;i<=n;i++){
		int len= g[i].size();
		if (len<2) continue;
		x= y= 0;
		for (j= 0;j<len;j++)
			if (a[i][g[i][j]]==1) x= 1;
			else y= 1;
		if (!x||!y){
			bl= 0;
			break;
		}
	}
	if (!bl) printf("No solution\n");
	else {
		for (i= 1;i<=n;i++){
			int len= g[i].size();
			x= y= 0;
			for (j= 0;j<len;j++)
				printf("%d ",a[i][g[i][j]]);
			printf("0\n");
		}
	}return 0;
}
