#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 300,oo= 1e9;
struct edge{
	int from,to,cap,flow;
};
struct node{
	int v;
	char c;
}ans[maxn];
vector<edge> edges;
vector<int> g[maxn];
queue<int> Q;
int wr[maxn],wc[maxn],vis[maxn],d[maxn],cur[maxn];
int n,m,i,j,x,y,z,flow,sum,s,t,la;
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
	d[s]= 0;
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();
		for (i= 0;i<len;i++){
			edge e= edges[g[u][i]];
			if (!vis[e.to]&&e.cap-e.flow>0){
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
			e.flow+= f;
			edges[g[o][i]^1].flow-= f;
			flow+= f;
			re-= f;
			if (!re) break;
		}
	}	
	return flow;
}
void find(int o){
	vis[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		edge e= edges[g[o][i]];
		if (!vis[e.to]&&e.cap-e.flow>0)
			find(e.to);		
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	s= 2*n+1;t= s+1;
	for (i= 1;i<=n;i++){
		scanf("%d",&wr[i]);
		addedge(i+n,t,wr[i]);
	}
	for (i= 1;i<=n;i++){
		scanf("%d",&wc[i]);
		addedge(s,i,wc[i]);
	}
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		addedge(x,y+n,oo);
	}
	while (bfs()){
		memset(cur,0,sizeof(cur));
		flow+= dfs(s,oo);
	}
	memset(vis,0,sizeof(vis));
	find(s);
	for (i= 1;i<=n;i++){
		if (!vis[i])
			ans[++la]= (node){i,'-'};
		if (vis[i+n])
			ans[++la]= (node){i,'+'};
	}
	printf("%d\n",flow);
	printf("%d\n",la);
	for (i= 1;i<=la;i++)
		printf("%d %c\n",ans[i].v, ans[i].c);
	return 0;
}
