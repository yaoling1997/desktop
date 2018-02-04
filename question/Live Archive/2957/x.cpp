#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 6e3,maxm= 60,oo= 1e9;
struct edge{
	int from,to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
vector<int> X[maxm];
queue<int> Q;
int A[maxm][maxm],B[maxm][maxm];
int vis[maxn],d[maxn],cur[maxn],Y[maxn],pos[maxm],ok[maxm],next[maxm];
int n,m,K,i,j,x,y,s,t,S,T,flow,D,C,tot;
void init(){
	memset(Y,0,sizeof(Y));
	memset(A,0,sizeof(A));
	memset(ok,0,sizeof(ok));
	memset(next,0,sizeof(next));
	edges.clear();
	int i;
	for (i= 0;i<=tot;i++) g[i].clear();
	for (i= 0;i<=n;i++)
		X[i].clear();
	s= 1;t= tot= 2;
	flow= D= 0;
}
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	Q.push(s);
	vis[s]= 1;
	d[s]= 0;
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();
		for (i= 0;i<len;i++){
			edge &e= edges[g[u][i]];
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
	int f,flow= 0,len= g[o].size();
	for (int &i= cur[o];i<len;i++){
		edge &e= edges[g[o][i]];
		if (d[e.to]==d[o]+1&&(f= dfs(e.to,min(re,e.cap-e.flow)))>0){
			flow+= f;
			re-= f;
			e.flow+= f;
			edges[g[o][i]^1].flow-= f;
			if (!re) return flow;
		}
	}return flow;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d%d%d%d%d",&n, &m, &K, &S, &T)>0){
		init();
		for (i= 1;i<=m;i++){
			scanf("%d%d",&x, &y);
			A[x][y]= A[y][x]= 1;
		}
		for (i= 1;i<=n;i++){
			X[i].push_back(++tot);
			Y[tot]= i;
		}
		addedge(s,X[S][0],K);
		for (;;){
			D++;
			for (i= 1;i<=n;i++){
				X[i].push_back(++tot);
				Y[tot]= i;
				addedge(X[i][D-1],X[i][D],oo);
			}
			addedge(X[T][D],t,oo);
			for (i= 1;i<=n;i++)
				for (j= i+1;j<=n;j++)
					if (A[i][j]){
						addedge(X[i][D-1],X[j][D],1);
						addedge(X[j][D-1],X[i][D],1);
					}
			while(bfs()){
				memset(cur,0,sizeof(cur));
				flow+= dfs(s,oo);
			}
			if (flow==K) break;
		}
		printf("%d\n",D);
		for (i= 1;i<=K;i++){
			pos[i]= S;
			Q.push(i);
		}
		int day= -1;
		while (!Q.empty()){
			day++;
			memset(B,0,sizeof(B));
			while (!Q.empty()){
				int u= Q.front(),o= X[pos[u]][day];
				int len= g[o].size(),i;
				Q.pop();
				for (i= 0;i<len;i++){
					edge &e= edges[g[o][i]];
					if (e.flow>0){
						e.flow--;
						next[u]= Y[e.to];
						if (pos[u]!=Y[e.to]){
							B[pos[u]][Y[e.to]]= u;
							int v= B[Y[e.to]][pos[u]];
							if (v){
								next[v]= pos[v];
								next[u]= pos[u];
							}
						}
						break;
					}
				}
			}
			C= 0;
			for(i= 1;i<=K;i++)
				if (!ok[i])
					if (next[i]!=pos[i]) C++;
			printf("%d",C);
			for(i= 1;i<=K;i++)
				if (!ok[i]){
					if (next[i]!=pos[i])
						printf(" %d %d",i, next[i]);
					pos[i]= next[i];
					if (pos[i]==T) ok[i]= 1;
					else Q.push(i);
				}
			printf("\n");
		}
	}return 0;
}
