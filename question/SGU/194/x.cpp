#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e2,maxm= 3e4,oo= 1e9;
struct edge{
	int from,to,cap,flow;
};
queue<int> Q;
vector<edge> edges;
vector<int> g[maxn];
vector<int> E;
int X[maxm],L[maxm],C[maxm],M[maxn],cur[maxn],d[maxn];
int vis[maxn];
int n,m,i,j,x,y,s,t,bl,flow;
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	Q.push(s);
	vis[s]= 1;
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
	int len= g[o].size(),f,flow= 0;
	for (int &i= cur[o];i<len;i++){
		edge &e= edges[g[o][i]];
		if (d[e.to]==d[o]+1&&(f= dfs(e.to,min(re,e.cap-e.flow)))>0){
			e.flow+= f;			
			edges[g[o][i]^1].flow-= f;
			flow+= f;
			re-= f;
			if (!re) break;
		}
	}return flow;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	bl= 1;
	for (i= 1;i<=m;i++){
		scanf("%d%d%d%d",&x, &y, &L[i], &C[i]);
		X[i]= edges.size();
		addedge(x,y,C[i]-L[i]);
		M[x]-= L[i];
		M[y]+= L[i];
	}
	s= n+1;t= n+2;
	for (i= 1;i<=n;i++){
		E.push_back(edges.size());
		if (M[i]>0) addedge(s,i,M[i]);
		else addedge(i,t,-M[i]);
	}
	while (bfs()){
		memset(cur,0,sizeof(cur));
		flow+= dfs(s,oo);
	}
	int len= E.size();
	for (i= 0;i<len;i++)
		if (edges[E[i]].cap-edges[E[i]].flow){
			bl= 0;
			break;
		}
	if (!bl) printf("NO");
	else {
		printf("YES\n");
		for (i= 1;i<=m;i++)
			printf("%d\n",L[i]+edges[X[i]].flow);
	}return 0;
}
