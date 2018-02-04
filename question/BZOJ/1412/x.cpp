#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;
const int maxn= 300,oo= 99999,maxl= 300000;
struct edge{
	int from,to,cap,flow;
};
int a[maxn][maxn],b[maxn][maxn];
vector<edge> edges;
vector<int>g[maxl];
int cur[maxl],vis[maxl],d[maxl],l[maxl];
int top,n,m,i,j,s,t,f,r,flow;
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	l[r= 1]= s;f= 0;vis[s]= 1;
	while (f<r){
		int u= l[++f],len= g[u].size();
		for (int i= 0;i<len;i++){
			edge e= edges[g[u][i]];
			if (!vis[e.to] && e.cap-e.flow){
				vis[e.to]= 1;
				d[e.to]= d[u]+1;
				l[++r]= e.to;
			}
		}
	}
	return vis[t];
}
int dfs(int o,int re){
	if (o==t || !re) return re;
	int flow= 0,len= g[o].size(),f;
	for (int &i= cur[o];i<len;i++){
		edge &e= edges[g[o][i]];
		if (d[e.to]==d[o]+1 && (f= dfs(e.to,min(e.cap-e.flow,re)))>0){
			flow+= f;
			re-= f;
			e.flow+= f;
			edges[g[o][i]^1].flow-= f;
			if (re==0) break;
		}
	}
	return flow;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);s= top= 1;t= n*m+2;
	memset(a,-1,sizeof(a));
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++){
			scanf("%d",&a[i][j]);
			b[i][j]= ++top;
		}
	for (i= 1;i<=n;i++)
		for (j= 1 ;j<=m;j++){
			top= b[i][j];
			if (a[i][j]==1){
				addedge(s,top,oo);
				if (a[i-1][j]==0 || a[i-1][j]==2)
					addedge(top,b[i-1][j],1);
				if (a[i][j-1]==0 || a[i][j-1]==2)
					addedge(top,b[i][j-1],1);
				if (a[i+1][j]==0 || a[i+1][j]==2)
					addedge(top,b[i+1][j],1);
				if (a[i][j+1]==0 || a[i][j+1]==2)
					addedge(top,b[i][j+1],1);				
			}else if (a[i][j]==0){
				if (abs(a[i-1][j])!=1)
					addedge(top,b[i-1][j],1);
				if (abs(a[i][j-1])!=1)
					addedge(top,b[i][j-1],1);
				if (abs(a[i+1][j])!=1)
					addedge(top,b[i+1][j],1);
				if (abs(a[i][j+1])!=1)
					addedge(top,b[i][j+1],1);				
			}else addedge(top,t,oo);
		}
	int len= edges.size();
	while (bfs()){
		memset(cur,0,sizeof(cur));
		flow+= dfs(s,oo);
	}
	printf("%d",flow);
}
