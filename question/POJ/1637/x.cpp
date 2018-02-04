#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 300,oo= 1e8;
struct edge{
	int from,to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
int vis[maxn],d[maxn],cur[maxn],D[maxn];
int s,t,i,j,n,m,x,y,z,flow,sum1,sum2,T;
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	queue<int> Q;
	Q.push(s);
	vis[s]= 1;
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
void init(int n){
	edges.clear();
	for (i= 1;i<=n;i++)	g[i].clear();
	g[s].clear(),g[t].clear();
	memset(D,0,sizeof(D));flow= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	s= 201;t= s+1;
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d %d",&n, &m);
		init(n);
		for (i= 1;i<=m;i++){
			scanf("%d %d %d\n",&x, &y, &z);
			if (z==1){
				D[x]++;D[y]--;
			}else {
				D[x]++;D[y]--;
				addedge(x,y,1);
			}
		}
		for (i= 1;i<=n;i++)
			if (D[i]&1){
				printf("impossible\n");
				break;
			}
		if (!(D[i]&1)){
			sum1= sum2= 0;
			for (i= 1;i<=n;i++){
				if (D[i]>0){
					sum1+= D[i]/= 2;
					addedge(s,i,D[i]);
				}
				else if (D[i]<0) {
					sum2+= D[i]/= -2;					
					addedge(i,t,D[i]);
				}
			}
			if (sum1!=sum2){
				printf("impossible\n");
				continue;
			}
			while (bfs()){
				memset(cur,0,sizeof(cur));
				flow+= dfs(s,oo);
			}
			if (flow==sum1) printf("possible\n");
			else printf("impossible\n");
		}
	}return 0;
}
