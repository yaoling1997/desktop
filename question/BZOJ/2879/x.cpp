#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 3001,maxm= 1000,oo= 1e9;
struct edge{
	int from,to,cap,flow,cost;
};
int vis[maxn],p[maxn],a[maxn],d[maxn];
int P[50],T[50][110],time[maxm],X[110],Y[maxn],b[maxm];
int n,m,i,j,flow,cost,tot,s,t;
vector<edge> edges;
vector<int> g[maxn];
void addedge(int from,int to,int cap,int cost){
	edges.push_back((edge){from,to,cap,0,cost});
	edges.push_back((edge){to,from,0,0,-cost});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool spfa(){
	int i;
	queue<int> Q;
	for (i= 1;i<=tot;i++) d[i]= oo;
	d[s]= 0;a[s]= oo;
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
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&P[i]);
		P[0]+= P[i];
	}
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			scanf("%d",&T[i][j]);
	s= n+m+1;tot= t= s+1;
	for (i= 1;i<=n;i++){
		addedge(s,i,P[i],0);
		for (j= 1;j<=m;j++)
			addedge(i,n+j,1,T[i][j]);
	}
	for (i= 1;i<=m;i++){
		time[i]= 1;
		Y[i+n]= i;
		X[i]= i+n;
		addedge(i+n,t,1,0);
	}
	for (i= 1;i<=P[0];i++){
		spfa();
		int len= g[t].size(),x= 0;
		for (j= 0;j<len;j++)
			if (!b[j]&&edges[g[t][j]].flow<0){
				x= edges[g[t][j]].to;
				b[j]= 1;
				break;
			}
		x= Y[x];
		X[x]= ++tot;
		Y[tot]= x;
		time[x]++;
		for (j= 1;j<=n;j++)
			addedge(j,tot,1,time[x]*T[j][x]);
		addedge(tot,t,1,0);
	}printf("%d\n",cost);
	return 0;
}
