#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 100,oo= 1e9;
struct edge{
	int from,to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
queue<int> Q;
int vis[maxn],d[maxn],cur[maxn],B[20][100];
int T,n,m,i,j,x,y,s,t,K,flow;
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	d[s]= 0;
	vis[s]= 1;
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
		if (d[e.to]==d[o]+1&&(f= dfs(e.to,min(e.cap-e.flow,re)))>0){
			flow+= f;
			re-= f;
			e.flow+= f;
			edges[g[o][i]^1].flow-= f;
			if (!re) return flow;
		}
	}return flow;
}
void init(){
	memset(B,0,sizeof(B));
	s= m+n+1;t= s+1;
	flow= 0;
	int i;
	edges.clear();
	for (i= 1;i<=t;i++) g[i].clear();
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int TT= 1;TT<=T;TT++){
		scanf("%d%d",&n, &m);
		init();
		for (i= 1;i<=n;i++){
			scanf("%d",&K);
			for (j= 1;j<=K;j++){
				scanf("%d",&x);
				B[i][x]++;
			}
		}
		for (i= 1;i<=m;i++){
			if (B[1][i])
				addedge(s,i,B[1][i]);
			addedge(i,t,1);
		}
		for (i= 2;i<=n;i++)
			for (j= 1;j<=m;j++)
				if (!B[i][j]) addedge(j,m+i,1);
				else if (B[i][j]>1)
					addedge(m+i,j,B[i][j]-1);
		while (bfs()){
			memset(cur,0,sizeof(cur));
			flow+= dfs(s,oo);
		}
		printf("Case #%d: %d\n",TT, flow);
	}return 0;
}
