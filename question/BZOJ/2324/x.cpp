#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 1000,maxm= 60000,oo= 2e8+10;
struct edge{
	int from,to,cap,flow,cost;
};
vector<edge> edges;
vector<int> g[maxm];
int f[maxn][maxn],l[maxm],d[maxm],a[maxm],vis[maxn],p[maxn];
int i,j,k,kk,n,s,t,s1,t1,base= 500,flow,cost,m,x,y,z;
void addedge(int from,int to,int cap,int cost){
	edges.push_back((edge){from,to,cap,0,cost});
	edges.push_back((edge){to,from,0,0,-cost});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
int spfa(int s,int t){
	int i,f,r;
	for (i= 0;i<=maxn-1;i++) d[i]= oo;
	memset(vis,0,sizeof(vis));
	d[s]= 0;f= 0;r= 1;l[1]= s;a[s]= oo;
	while (f<r){
		int u= l[++f],len= g[u].size();
		vis[u]= 0;
		for (i= 0;i<len;i++){
			edge e= edges[g[u][i]];
			if ((d[e.to]>d[u]+e.cost) && (e.cap-e.flow)){
				d[e.to]= d[u]+e.cost;
				a[e.to]= min(a[u],e.cap-e.flow);
				p[e.to]= g[u][i];
				if (!vis[e.to]){
					vis[e.to]= 1;
					l[++r]= e.to;
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
	}
	return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d\n",&n, &m, &kk);
	for (i= 0;i<=n;i++)
		for (j= 0;j<=n;j++)
			if (i!=j)
				f[i][j]= oo;
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		if (z<f[x][y])
			f[x][y]= f[y][x]= z;
	}
	for (k= 0;k<=n;k++)
		for (i= k+1;i<=n;i++)
			for (j= k+1;j<=n;j++)
				f[i][j]= min(f[i][j],f[i][k]+f[k][j]);
	s= n+1;t= s+1;s1= t+1;t1= s1+1;
	addedge(s,base,kk,0);addedge(base,t,kk,0);
	for (i= 0;i<n;i++)
		for (j= i+1;j<=n;j++)
			if (f[i][j]!=oo)
				addedge(i+base,j,kk,f[i][j]);
	for (i= 1;i<=n;i++){
		addedge(i,i+base,kk-1,0);
		addedge(i,t1,1,0);
		addedge(s1,i+base,1,0);
		addedge(i+base,t,kk,0);
	}
	addedge(t,s,oo,0);
	while(spfa(s1,t1));
	while(spfa(s,t));
	printf("%d",cost);
	return 0;
}
