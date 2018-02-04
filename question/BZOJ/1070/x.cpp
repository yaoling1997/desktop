#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 3001,maxl= 100,oo= 1e9;
struct edge{
	int from,to,cap,flow,cost;
};
vector<edge> edges;
vector<int> g[maxn];
int d[maxn],vis[maxn],a[maxn],p[maxn];
int T[maxl][maxl],time[maxl],X[maxl],Y[maxn],b[maxl];
int s,t,i,j,n,m,tot,flow,cost;
void addedge(int from,int to,int cap,int cost){
	edges.push_back((edge){from,to,cap,0,cost});
	edges.push_back((edge){to,from,0,0,-cost});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool spfa(){
	int i;
	for (i= 1;i<=tot;i++) d[i]= oo;
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
				p[e.to]= g[u][i];
				a[e.to]= min(a[u],e.cap-e.flow);
				if (!vis[e.to]){
					vis[e.to]= 1;
					Q.push(e.to);
				}
			}
		}
	}
	if (d[t]==oo) return 0;
	flow+= a[t];cost+= a[t]*d[t];
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
	scanf("%d %d",&m, &n);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			scanf("%d",&T[i][j]);
	s= n+m+1;tot= t= s+1;
	for (i= 1;i<=n;i++){
		addedge(s,i,1,0);
		for (j= 1;j<=m;j++)
			addedge(i,j+n,1,T[i][j]);
	}
	for (i= 1;i<=m;i++){
		X[i]= i+n;
		Y[i+n]= i;
		time[i]= 1;
		addedge(i+n,t,1,0);
	}
	for (i= 1;i<=n;i++){
		spfa();
		int len= g[t].size(),x= 0;
		for (j= 0;j<len;j++)
			if (!b[j]&&edges[g[t][j]].flow<0){
				b[j]= 1;
				x= edges[g[t][j]].to;
			}
		x= Y[x];
		X[x]= ++tot;
		Y[tot]= x;
		time[x]++;
		addedge(tot,t,1,0);
		for (j= 1;j<=n;j++)
			addedge(j,tot,1,time[x]*T[j][x]);
	}printf("%.2lf\n",(double)cost/n);
	return 0;
}
