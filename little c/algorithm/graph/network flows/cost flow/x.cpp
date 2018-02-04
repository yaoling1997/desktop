#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 3001,oo= 99999;
struct edge{
	int from,to,cap,flow,cost;
};
vector<edge> edges;
vector<int> g[maxn];
queue<int> Q;
int d[maxn],a[maxn],p[maxn],vis[maxn];
int i,x1,x2,x3,x4,n,m,s,t,flow,cost;
void addedge(int from,int to,int cap,int cost){
	edges.push_back((edge){from,to,cap,0,cost});
	edges.push_back((edge){to,from,0,0,-cost});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool spfa(){
	int i;
	for (i= 1;i<=n;i++)
		d[i]= oo,vis[i]= 0;
	d[s]= 0;vis[s]= 1;a[s]= oo;
	Q.push(s);
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size();
		Q.pop();vis[u]= 0;
		for (i= 0;i<len;i++){
			edge& e= edges[g[u][i]];
			if (d[u]+e.cost<d[e.to] && e.cap>e.flow){
				d[e.to]= d[u]+e.cost;
				a[e.to]= min(a[u],e.cap-e.flow);
				p[e.to]= g[u][i];
				if (!vis[e.to]){
					vis[e.to]= 1;
					Q.push(e.to);
				}
			}
		}
	}
	if (d[t]==oo) return 0;
	flow+= a[t];
	cost+= d[t]*a[t];
	int u= t;
	while (u!=s){
		edges[p[u]].flow+= a[t];
		edges[p[u]^1].flow-= a[t];
		u= edges[p[u]].from;
	}
	return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d%d%d",&n, &m, &s, &t);
	for (int i= 1;i<=m;i++){
		scanf("%d%d%d%d",&x1, &x2, &x3, &x4);
		addedge(x1,x2,x3,x4);
	}
	while (spfa());
	printf("%d %d",flow, cost);
	return 0;
}
