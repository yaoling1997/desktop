#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 200,base= 1111,oo= 2e8;
struct edge{
	int from,to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
queue<int> Q;
int cur[maxn],vis[maxn],d[maxn];
int s,t,n,m,i,j,x,y,z,a1,a2,a3,flow,T,sum;
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap*base-1,0});
	edges.push_back((edge){to,from,cap*base-1,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
void init(){
	int i;
	edges.clear();
	for (i= 1;i<=n;i++)
		g[i].clear();
	flow= sum= 0;
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	Q.push(s);
	vis[s]= 1;
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();
		for (i= 0;i<len;i++){
			edge &e= edges[g[u][i]];
			if (!vis[e.to] && e.cap-e.flow>0){
				vis[e.to]= 1;
				Q.push(e.to);
				d[e.to]= d[u]+1;
			}
		}
	}return vis[t];
}
int dfs(int o,int re){
	if (o==t || !re) return re;
	int f,flow= 0,len= g[o].size();
	for (int &i= cur[o];i<len;i++){
		edge &e= edges[g[o][i]];
		if (d[o]+1==d[e.to] && (f= dfs(e.to,min(re,e.cap-e.flow)))>0){
			flow+= f;
			re-= f;
			e.flow+= f;
			edges[g[o][i]^1].flow-= f;
			if (!re) return flow;
		}
	}return flow;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int NN= 1;NN<=T;NN++){
		scanf("%d%d%d%d",&n, &m, &s, &t);
		init();
		for (i= 1;i<=m;i++){
			scanf("%d%d%d",&x, &y, &z);
			addedge(x,y,z);
			sum+= z;
		}
		while (bfs()){
			memset(cur,0,sizeof(cur));
			flow+= dfs(s,oo);
		}
		if (!flow){
			printf("Inf\n");
			continue;
		}
		a1= flow/base+1;
		a2= a1*base-flow;
		a1= sum-a1;		
		printf("%.2lf\n",(double)a1/a2);
	}return 0;
}
	
