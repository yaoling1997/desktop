#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 3001,oo= 1e8;
struct edge{
	int from,to,cap,flow,cost;
};
vector<edge> edges;
vector<int> g[maxn];
int a[maxn],p[maxn],d[maxn],vis[maxn];
int n,m,x,y,z,i,flow,cost,s,t;
void addedge(int from,int to,int cap,int cost){
	edges.push_back((edge){from,to,cap,0,cost});
	edges.push_back((edge){to,from,0,0,-cost});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool spfa(){
	memset(vis,0,sizeof(vis));	
	for (int i= 1;i<=t;i++)	d[i]= oo;
	a[s]= oo;d[s]= 0;
	queue<int> Q;Q.push(s);
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();vis[u]= 0;
		for (i= 0;i<len;i++){
			edge e= edges[g[u][i]];
			if (d[e.to]>d[u]+e.cost&&e.cap-e.flow){
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
	cost+= a[t]*d[t];
	int u= t;
	while (u!=s){
		edges[p[u]].flow+= a[t];
		edges[p[u]^1].flow-= a[t];
		u= edges[p[u]].from;
	}return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		addedge(x,y,1,z);
		addedge(y,x,1,z);
	}s= n+1;t= s+1;
	addedge(s,1,2,0);addedge(n,t,2,0);
	while (spfa());
	printf("%d\n",cost);
	return 0;
}
