#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;
const int maxn= 3001,oo= 99999999;
struct edge{
	int from,to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
int cur[maxn],d[maxn],l[maxn];
bool vis[maxn];
int n,m,s,t,i,j,x,y,z;
int flow;
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	int f= 0,r= 1;
	l[r]= s;vis[s]= 1;
	while (f<r){
		int i,u= l[++f],len =g[u].size();
		for (i= 0;i<len;i++){
			edge &e= edges[g[u][i]];
			if (!vis[e.to] && (e.cap-e.flow>0)){
				vis[e.to]= 1;
				d[e.to]= d[u]+1;
				l[++r]= e.to;
			}
		}
	}
	return vis[t];
}
int dfs(int o,int re){
	if (o==t || re==0) return re;
	int f,flow= 0,len= g[o].size();
	for (int &i= cur[o];i<len;i++){
		edge &e= edges[g[o][i]];
		if (d[o]+1==d[e.to] && (f= dfs(e.to,min(re,e.cap-e.flow)))>0){
			flow+= f;
			re-= f;
			e.flow+= f;
			edges[g[o][i]^1].flow-= f;
			if (!re) break;
		}
	}
	return flow;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d %d\n",&x, &y, &z);
		addedge(x,y,z);
	}
	while (bfs()){
		memset(cur,0,sizeof(cur));
		flow+= dfs(s,oo);
	}
	printf("%d",flow);
	return 0;
}
