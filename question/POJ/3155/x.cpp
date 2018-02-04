#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const double eps= 1e-8,oo= 1e9;
const int maxn= 300,maxm= 2000;
struct line{
	int x,y;
}L[maxm];
struct edge{
	int from,to;
	double cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
queue<int> Q;
int d[maxn],vis[maxn],cur[maxn],D[maxn],ans[maxn];
double l,r,mid,U;
int s,t,n,m,i,j,x,y,z,la;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
void addedge(int from,int to,double cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);	
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	d[s]= 0;
	Q.push(s);
	vis[s]= 1;
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();
		for (i= 0;i<len;i++){
			edge e= edges[g[u][i]];
			if (!vis[e.to]&&dcmp(e.cap-e.flow)>0){
				vis[e.to]= 1;
				d[e.to]= d[u]+1;
				Q.push(e.to);
			}
		}
	}return vis[t];
}
double dfs(int o,double re){
	if (o==t||!dcmp(re)) return re;
	double flow= 0,f;
	int len= g[o].size();
	for (int &i= cur[o];i<len;i++){
		edge &e= edges[g[o][i]];
		if (d[o]+1==d[e.to]&&dcmp(f= dfs(e.to,min(e.cap-e.flow,re)))>0){
			e.flow+= f;
			edges[g[o][i]^1].flow-= f;
			flow+= f;
			re-= f;
			if (!re) break;
		}
	}return flow;
}
void prepare(){
	edges.clear();
	for (int i= 1;i<=t;i++)
		g[i].clear();
}
double get(double g){
	int i;
	prepare();	
	for (i= 1;i<=m;i++){
		addedge(L[i].x,L[i].y,1);
		addedge(L[i].y,L[i].x,1);		
	}
	for (i= 1;i<=n;i++){
		addedge(s,i,U);
		addedge(i,t,U+2*g-D[i]);
	}
	double flow= 0,h;
	while (bfs()){
		memset(cur,0,sizeof(cur));
		flow+= dfs(s,oo);
	}
	h= (U*n-flow)/2;
	return h;
}
void find(int o){
	vis[o]= 1;
	if (o!=s) ans[++la]= o;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		edge e= edges[g[o][i]];
		if (vis[e.to]||!dcmp(e.cap-e.flow)) continue;
		find(e.to);
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	while (scanf("%d%d",&n, &m)>0){
		if (!m){
			printf("1\n1");
			return 0;
		}
		for (i= 1;i<=m;i++){
			scanf("%d%d",&x, &y);
			D[x]++;
			D[y]++;
			L[i]= (line){x,y};
		}
		s= n+1;
		t= s+1;
		l= 0;r= m;
		U= m;
		while (r-l>1e-6){
			double g= (l+r)/2;
			if (get(g)>eps) l= g;
			else r= g;
		}
		get(l);
		memset(vis,0,sizeof(vis));
		la= 0;
		find(s);
		sort(ans+1,ans+la+1);
		printf("%d\n",la);
		for (i= 1;i<=la;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
