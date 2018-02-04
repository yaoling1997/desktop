#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxl= 30,maxn= 3001,oo= 1e8;
struct edge{
	int from,to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
char S[maxl];
int map[maxl][maxl],r[maxl][maxl],c[maxl][maxl];
int d[maxn],vis[maxn],cur[maxn],stack[maxn];
int n,m,D,i,j,k,z,tot,flow,top,s,t;
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool bfs(){
	int i;
	for (i= 0;i<=tot;i++) vis[i]= 0;
	queue<int> Q;
	Q.push(s);vis[s]= 1;
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size();
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
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &m, &D);
	for (i= 1;i<=n;i++){
		scanf("%s",S+1);
		for (j= 1;j<=m;j++){
			map[i][j]= S[j]-'0';
			if (map[i][j]){
				r[i][j]= ++tot;
				c[i][j]= ++tot;
				addedge(tot-1,tot,map[i][j]);
			}
		}
	}
	for (i= 1;i<=n;i++){
		scanf("%s",S+1);
		for (j= 1;j<=m;j++)
			if (S[j]=='L'){
				stack[++top]= ++tot;
				addedge(tot,r[i][j],1);
			}
	}
	s= ++tot;t= ++tot;
	for (i= 1;i<=top;i++)
		addedge(s,stack[i],1);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++){
			if (c[i][j]==0) continue;
			for (k= 1;k<=n;k++)
				for (z= 1;z<=m;z++){
					if (i==k&&j==z) continue;
					if (abs(k-i)+abs(z-j)<=D)
						addedge(c[i][j],r[k][z],oo);
				}
			if (i<=D||j<=D||i+D>n||j+D>m)
				addedge(c[i][j],t,oo);
		}
	while (bfs()){
		for (i= 0;i<=tot;i++) cur[i]= 0;
		flow+= dfs(s,oo);
	}printf("%d",top-flow);
	return 0;
}
