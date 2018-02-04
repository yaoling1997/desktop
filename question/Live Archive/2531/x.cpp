#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 30,maxm= 1000,oo= 1e9;
struct edge{
	int from,to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxm];
queue<int> Q;
int a[maxn][maxn];
int W[maxn],D[maxn],vis[maxm],cur[maxm],d[maxm];
int T,n,i,j,x,y,flow,la,M,s,t,tot,cnt;
void init(){
	cnt= 0;
}
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	vis[s]= 1;
	d[s]= 0;
	Q.push(s);
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();
		for (i= 0;i<len;i++){
			edge &e= edges[g[u][i]];
			if (!vis[e.to]&&e.cap>e.flow){
				vis[e.to]= 1;
				d[e.to]= d[u]+1;
				Q.push(e.to);
			}
		}
	}return vis[t];
}
int dfs(int o,int re){
	if (o==t||!re) return re;
	int f,flow= 0,len= g[o].size();
	for (int &i= cur[o];i<len;i++){
		edge &e= edges[g[o][i]];
		if (d[e.to]==d[o]+1&&(f= dfs(e.to,min(re,e.cap-e.flow)))>0){
			flow+= f;
			re-= f;
			e.flow+= f;
			edges[g[o][i]^1].flow-= f;
			if (!re) return flow;
		}
	}return flow;
}
void solve(int o){
	int i,j,sum= 0;
	edges.clear();
	for (i= 1;i<=tot;i++) g[i].clear();
	flow= 0;
	s= n+1;t= tot= n+2;
	for (i= 1;i<=n;i++){
		if (i==o) continue;
		for (j= i+1;j<=n;j++){
			if (j==o) continue;
			if (!a[i][j]) continue;
			tot++;
			addedge(s,tot,a[i][j]);
			sum+= a[i][j];
			addedge(tot,i,oo);
			addedge(tot,j,oo);
		}
		addedge(i,t,M-W[i]);
	}
	while (bfs()){
		memset(cur,0,sizeof(cur));
		flow+= dfs(s,oo);
	}
	if (flow==sum){
		cnt++;		
		if (cnt!=1) printf(" ");
		printf("%d",o);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		init();
		for (i= 1;i<=n;i++)
			scanf("%d%d",&W[i], &D[i]);
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++)
				scanf("%d",&a[i][j]);
		for (i= 1;i<=n;i++){
			int bl= 1;
			M= W[i];
			for (j= 1;j<=n;j++)
				M+= a[i][j];
			for (j= 1;j<=n;j++)
				if (M<W[j]){
					bl= 0;
					break;
				}
			if (bl)
				solve(i);
		}
		printf("\n");
	}return 0;
}
