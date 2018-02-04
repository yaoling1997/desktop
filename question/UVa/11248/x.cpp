#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 300,oo= 1e9;
struct edge{
	int from,to,cap,flow;
};
struct node{
	int x,y;
	bool operator <(const node &a)const{
		return x<a.x||(x==a.x&&y<a.y);
	}
};
vector<edge> edges,Edges;
vector<int> g[maxn],G[maxn];
queue<int> Q;
vector<node> sta;
int vis[maxn],d[maxn],cur[maxn];
int n,m,C,i,x,y,z,flow,s,t,cnt;
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
int bfs(){
	memset(vis,0,sizeof(vis));
	d[s]= 0;vis[s]= 1;
	Q.push(s);
	while (!Q.empty()){
		int u=Q.front(),len= g[u].size(),i;
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
			if (!re) return flow;
		}
	}return flow;
}
int Bfs(){
	memset(vis,0,sizeof(vis));
	d[s]= 0;vis[s]= 1;
	Q.push(s);
	while (!Q.empty()){
		int u=Q.front(),len= G[u].size(),i;
		Q.pop();
		for (i= 0;i<len;i++){
			edge e= Edges[G[u][i]];
			if (!vis[e.to]&&e.cap-e.flow){
				vis[e.to]= 1;
				d[e.to]= d[u]+1;
				Q.push(e.to);
			}
		}
	}return vis[t];
}
int Dfs(int o,int re){
	if (o==t||!re) return re;
	int flow= 0,f,len= G[o].size();
	for (int &i= cur[o];i<len;i++){
		edge &e= Edges[G[o][i]];
		if (d[e.to]==d[o]+1&&(f= Dfs(e.to,min(re,e.cap-e.flow)))>0){
			flow+= f;
			re-= f;
			e.flow+= f;
			Edges[G[o][i]^1].flow-= f;
			if (!re) return flow;
		}
	}return flow;
}
void check(int o){
	int i,Flow= flow;
	Edges.clear();
	Edges= edges;
	for (i= 1;i<=t;i++){
		G[i].clear();
		G[i]= g[i];
	}
	Edges[o].cap= oo;
	while (Bfs()){
		memset(cur,0,sizeof(cur));
		Flow+= Dfs(s,oo);
	}
	if (Flow==C)
		sta.push_back((node){edges[o].from,edges[o].to});
}
void init(){
	flow= 0;
	s= n+1;t= s+1;
	edges.clear();
	sta.clear();
	for (int i= 1;i<=t;i++)
		g[i].clear();
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while(scanf("%d%d%d",&n, &m, &C)){
		if (!n) break;
		cnt++;
		init();
		printf("Case %d: ",cnt);
		for (i= 1;i<=m;i++){
			scanf("%d%d%d",&x, &y, &z);
			addedge(x,y,z);
		}
		addedge(s,1,C);
		addedge(n,t,C);
		while (bfs()){
			memset(cur,0,sizeof(cur));
			flow+= dfs(s,oo);
		}
		if (flow==C){
			printf("possible\n");
			continue;
		}
		int len= edges.size();
		for (i= 0;i<len-4;i+= 2){
			edge &e= edges[i];
			if (e.cap==e.flow)
				check(i);			
		}
		if (sta.empty()) printf("not possible\n");
		else {
			printf("possible option:");
			sort(sta.begin(),sta.end());
			printf("(%d,%d)",sta[0].x, sta[0].y);
			int la= sta.size();
			for (i= 1;i<la;i++)
				printf(",(%d,%d)",sta[i].x, sta[i].y);
			printf("\n");
		}
	}return 0;
}
