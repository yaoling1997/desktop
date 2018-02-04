#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int maxn= 1e6+10;
vector<int> gg[maxn],g[maxn];
set<int> X[maxn];
int pre[maxn],low[maxn],stack[maxn],F[maxn],G[maxn];
int sccno[maxn],vis[maxn],scc[maxn];
int n,m,mo,i,j,x,y,time,top,cnt,ans,ans2;
void dfs(int o){
	stack[++top]= o;
	low[o]= pre[o]= ++time;
	int i,len= gg[o].size();
	for (i= 0;i<len;i++){
		int v= gg[o][i];
		if (!pre[v]){
			dfs(v);
			low[o]= min(low[o],low[v]);
		}else if (!sccno[v])
			low[o]= min(low[o],pre[v]);
	}
	if (low[o]==pre[o]){
		cnt++;
		for (;;){
			x= stack[top--];
			sccno[x]= cnt;
			scc[cnt]++;
			if (x==o) break;
		}
	}
}
void update(int &a,int b){
	a+= b;
	a-= a/mo*mo;
}
void DFS(int o){	
	if (F[o]>=0) return;
	int len= g[o].size(),i;
	if (!len){
		F[o]= scc[o];
		G[o]= 1;
		if (ans<F[o]){
			ans= F[o];
			ans2= G[o];
		}else if (ans==F[o])
			update(ans2,G[o]);
		return;
	}F[o]= G[o]= 0;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		DFS(v);
		if (F[o]<F[v]+scc[o]){
			F[o]= F[v]+scc[o];
			G[o]= G[v];
		}else if (F[o]==F[v]+scc[o])
			update(G[o],G[v]);
	}
	if (ans<F[o]){
		ans= F[o];
		ans2= G[o];
	}else if (ans==F[o])
		update(ans2,G[o]);	
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &m, &mo);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		gg[x].push_back(y);
	}
	for (i= 1;i<=n;i++)
		if (!pre[i])
			dfs(i);
	for (i= 1;i<=n;i++){
		int u= sccno[i],len= gg[i].size();
		X[u].insert(u);
		for (j= 0;j<len;j++){
			int v= sccno[gg[i][j]];
			if (X[u].count(v)) continue;
			g[u].push_back(v);
			X[u].insert(v);
		}
	}
	for (i= 1;i<=cnt;i++)
		F[i]= -1;
	for (i= 1;i<=cnt;i++)
		if (!vis[i])
			DFS(i);
	printf("%d\n%d",ans, ans2);
	return 0;
}
