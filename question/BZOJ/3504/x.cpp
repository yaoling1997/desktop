#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 100,oo= 1e8;
struct edge{
	int from,to,cap,flow,cost;
};
vector<edge> edges;
vector<int> g[maxn];
int vis[maxn],d[maxn],a[maxn],p[maxn];
char ch;
int a1,a2,b1,b2,an,bn,n,flow,s,t,i,j,cost;
void addedge(int from,int to,int cap,int cost){
	edges.push_back((edge){from,to,cap,0,cost});
	edges.push_back((edge){to,from,0,0,-cost});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool spfa(){
	for (int i= 1;i<=t;i++)	d[i]= oo;
	d[s]= 0;a[s]= oo;
	queue<int> Q;
	Q.push(s);
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
	flow+= a[t],cost+= a[t]*d[t];
	int u= t;
	while (u!=s){
		edges[p[u]].flow+= a[t];
		edges[p[u]^1].flow-= a[t];
		u= edges[p[u]].from;
	}return 1;
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
	for (i= 1;i<=8;i++)	{
		int u= edges[edges.size()-1].from;
		g[u].pop_back();
		edges.pop_back();
	}
	for (i= 0;i<edges.size();i++) edges[i].flow= 0;
	addedge(s,a1,an,0);
	addedge(s,b2,bn,0);
	addedge(a2,t,an,0);
	addedge(b1,t,bn,0);
	flow= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	s= 60;t= s+1;
	while (scanf("%d %d %d %d %d %d %d\n",&n, &a1, &a2, &an, &b1, &b2, &bn)!=EOF){a1++;a2++;b1++;b2++;
		init(n);
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++){
				ch= read();
				if (ch=='O') addedge(i,j,2,1);
				else if (ch=='N') addedge(i,j,oo,1);
			}
		an*= 2;bn*= 2;
		addedge(s,a1,an,0);
		addedge(s,b1,bn,0);
		addedge(a2,t,an,0);
		addedge(b2,t,bn,0);
		while (spfa());
		if (flow==an+bn){
			clear();
			while (spfa());
			if (flow==an+bn){
				printf("Yes\n");
				continue;
			}
		} printf("No\n");
	}return 0;
}
