#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
const int maxn= 3001;
vector<int> g[maxn],g2[maxn],scc[maxn];
int vis[maxn],stack[maxn],sccno[maxn];
int n,m,x,y,i,j,la,cnt;
void dfs(int o){
	vis[o]= 1;
	int len= g[o].size();
	for (int i= 0;i<len;i++){
		int v= g[o][i];
		if (!vis[v]) dfs(v);
	}
	stack[++la]= o;
}
void dfs1(int o){
	sccno[o]= cnt;
	scc[cnt].push_back(o);
	int len= g2[o].size();
	for (int i= 0;i<len;i++){
		int v= g2[o][i];
		if (!sccno[v]) dfs1(v);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		g[x].push_back(y);
		g2[y].push_back(x);
	}
	for (i= 1;i<=n;i++)
		if (!vis[i]) dfs(i);
	for (i= la;i>0;i--)
		if (!sccno[stack[i]]){
			cnt++;
			dfs1(stack[i]);
		}
	printf("%d\n",cnt);
	for (i= 1;i<=cnt;i++){
		int len= scc[i].size();
		for (j= 0;j<len;j++)
			printf("%d ",scc[i][j]);
		printf("\n");
	}
	return 0;
}
