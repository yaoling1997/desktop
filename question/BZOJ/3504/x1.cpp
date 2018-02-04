#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 55,oo= 1e8;
struct edge{
	int from,to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
int cur[maxn],vis[maxn],d[maxn];
char ch;
int a1,a2,b1,b2,an,bn,n,flow,s,t,i,j;
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,cap,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	queue<int> Q;vis[s]= 1;
	Q.push(s);
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();
		for (i= 0;i<len;i++){
			edge e= edges[g[u][i]];
			if (!vis[e.to]&&e.cap-e.flow){
				vis[e.to]= 1;
				d[e.to]= d[u]+1;
				Q.push(e.to);
			}
		}
	}
	return vis[t];
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
char read(){
	char c;
	for (;;){
		c= getchar();
		if (c=='O'||c=='X'||c=='N') return c;
	}
}
void init(int n){
	int i;
	edges.clear();
	for (i= 1;i<=n;i++)
		g[i].clear();
	g[s].clear(),g[t].clear();
	flow= 0;
}
void clear(){
	int i;
	for (i= 1;i<=8;i++){
		int u= edges[edges.size()-1].from;
		g[u].pop_back();
		edges.pop_back();
	}
	for (i= 0;i<edges.size();i++) edges[i].flow= 0;
	addedge(s,a1,an);
	addedge(s,b2,bn);
	addedge(a2,t,an);
	addedge(b1,t,bn);
	flow= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	s= 51;t= s+1;
	while (scanf("%d %d %d %d %d %d %d\n",&n, &a1, &a2, &an, &b1, &b2, &bn)!=EOF){a1++;a2++;b1++;b2++;
		init(n);
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++){
				ch= read();
				if (j>=i){
					if (ch=='O') addedge(i,j,2);
					else if (ch=='N') addedge(i,j,oo);
				}
			}
		an*= 2;bn*= 2;
		addedge(s,a1,an);
		addedge(s,b1,bn);
		addedge(a2,t,an);
		addedge(b2,t,bn);
		while (bfs()){
			memset(cur,0,sizeof(cur));
			flow+= dfs(s,oo);
		}
		if (flow==an+bn){
			clear();
			while (bfs()){
				memset(cur,0,sizeof(cur));
				flow+= dfs(s,oo);
			}if (flow==an+bn){
				printf("Yes\n");
				continue;
			}
		} printf("No\n");
	}return 0;
}
