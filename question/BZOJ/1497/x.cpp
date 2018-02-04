#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 300001,oo= 1e8;
struct edge{
	int from,to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
int p[maxn],d[maxn],vis[maxn],cur[maxn];
int i,j,n,m,x,y,z,flow,s,t,sum,tot;
void addedge(int x,int y,int z){
	edges.push_back((edge){x,y,z,0});
	edges.push_back((edge){y,x,0,0});
	int m= edges.size();
	g[x].push_back(m-2);
	g[y].push_back(m-1);
}
bool bfs(){
	queue<int> Q;
	int i;
	for (i= 1;i<=tot;i++) vis[i]= 0;
	Q.push(s);vis[s]= 1;
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size();
		Q.pop();
		for (i= 0;i<len;i++){
			edge e= edges[g[u][i]];
			if (!vis[e.to]&&e.cap-e.flow){
				vis[e.to]= 1;
				d[e.to]= d[u]+1;
				Q.push(e.to);
			}
		}
	}return vis[t];
}
int dfs(int o,int re){
	if (o==t||!re) return re;
	int flow= 0,f,len= g[o].size();
	for (int &i= cur[o];i<len;i++){
		edge &e= edges[g[o][i]];
		if (d[e.to]==d[o]+1&&(f= dfs(e.to,min(re,e.cap-e.flow)))>0){
			flow+= f;
			re-= f;
			e.flow+= f;
			edges[g[o][i]^1].flow-= f;
			if (!re) break;
		}
	}return flow;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);s= n+1;t= n+2;
	for (i= 1;i<=n;i++){
		scanf("%d",&p[i]);
		addedge(i,t,p[i]);
	}
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		addedge(s,i+n+2,z);
		addedge(i+n+2,x,oo);
		addedge(i+n+2,y,oo);
		sum+= z;
	}tot= n+2+m;
	while (bfs()){
		for (i= 1;i<=tot;i++) cur[i]= 0;
		flow+= dfs(s,oo);
	}printf("%d\n",sum-flow);
	return 0;
}
