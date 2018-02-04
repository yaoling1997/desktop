#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn= 3001;
vector<int> bcc[maxn];
int head[maxn],next[maxn],des[maxn];
int pre[maxn],low[maxn],vis[maxn],cut[maxn];
int n,m,i,j,x,y,top,time;
void dfs(int o,int fa){
	pre[o]= low[o]= ++time;
	int p= head[o];
	while (p){
		int v= des[p];
		if (!pre[v]){
			dfs(v,p|1);
			low[o]= min(low[o],low[v]);
			if (low[v]>pre[o])
				cut[p]= cut[p^1]= 1;
		}else if (pre[v]<pre[o] && (p|1)!=fa)
			low[o]= min(low[o],pre[v]);
		p= next[p];
	}
}
void dfs1(int o){
	vis[o]= 1;bcc[top].push_back(o);
	int p= head[o];
	while (p){
		if (!cut[p]){
			int v= des[p];
			if (!vis[v]) dfs1(v);
		}
		p= next[p];
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	top= 1;
	for (i= 1;i<=m;i++){
		top++;
		scanf("%d %d",&x, &y);
		des[top]= y;
		next[top]= head[x];
		head[x]= top;
		top++;
		des[top]= x;
		next[top]= head[y];
		head[y]= top;
	}
	for (i= 1;i<=n;i++)
		if (!pre[i])
			dfs(i,-1);
	top= 0;
	for (i= 1;i<=n;i++)
		if (!vis[i]){
			top++;
			dfs1(i);
		}
	printf("%d\n",top);
	for (i= 1;i<=top;i++){
		int len= bcc[i].size();
		for (j= 0;j<len;j++)
			printf("%d ",bcc[i][j]);
		printf("\n");
	}
	return 0;
}
