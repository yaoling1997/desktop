#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
using namespace std;
const double eps= 1e-8;
const int maxn= 500,maxm= 500,oo= 1e9;
struct E{
	int x,y,c;
}L[maxm];
struct edge{
	int from,to;
	double cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
queue<int> Q;
int vis[maxn],d[maxn],cur[maxn],ans[maxn],sta[maxn];
int S[maxn];
double l,r,flow,o;
int n,m,i,j,x,y,z,cnt,s,t,T;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
void addedge(int from,int to,double cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,cap,0});
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
	if (o==t||!re) return re;
	double flow= 0,f;
	int len= g[o].size();
	for (int &i= cur[o];i<len;i++){
		edge &e= edges[g[o][i]];
		if (d[e.to]==d[o]+1&&dcmp(f= dfs(e.to,min(re,e.cap-e.flow)))>0){
			e.flow+= f;
			edges[g[o][i]^1].flow-= f;
			flow+= f;
			re-= f;
			if (!dcmp(re)) break;
		}
	}return flow;
}
void init(double numda){
	int i;
	s= 1;
	t= n;
	memset(ans,0,sizeof(ans));
	edges.clear();
	flow= 0;
	for (i= 1;i<=n;i++)
		g[i].clear();
	for (i= 1;i<=m;i++){
		double x= L[i].x,y= L[i].y,z= L[i].c-numda;
		if (dcmp(z)<0){
			flow+= z;
			ans[i]= 1;
		}else if (dcmp(z)>0)
			addedge(x,y,z);		
	}
}
void find(int o){
	if (S[o]) return;
	S[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		edge e= edges[g[o][i]];
		if (!dcmp(e.cap-e.flow))
			continue;		
		find(e.to);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d%d",&n, &m)>0){
		T++;
		//if (T>1) printf("\n");
		for (i= 1;i<=m;i++){
			scanf("%d%d%d",&x, &y, &z);
			L[i]= (E){x,y,z};
		}
		l= 0;r= oo;
		for (i= 1;i<=50;i++){
			double m= (l+r)/2;
			init(m);
			while (bfs()){
				memset(cur,0,sizeof(cur));
				flow+= dfs(s,oo);
			}
			if (flow<0) r= m;
			else l= m;
			}
		/*while (l+(1e-5)<r){
			double m= (l+r)/2;
			init(m);
			while (bfs()){
				memset(cur,0,sizeof(cur));
				flow+= dfs(s,oo);
			}
			if (flow<0) r= m;
			else l= m;
			}*/
		init(l);
		while (bfs()){
			memset(cur,0,sizeof(cur));
			flow+= dfs(s,oo);
		}		
		//printf("%.2lf\n",l);
		memset(S,0,sizeof(S));
		find(s);
		for (i= 1;i<=m;i++){
			x= L[i].x;
			y= L[i].y;
			if (S[x]&&S[y]) continue;
			if (!S[x]&&!S[y]) continue;
			ans[i]= 1;
		}
		cnt= 0;
		for (i= 1;i<=m;i++)
			if (ans[i])
				sta[++cnt]= i;
		printf("%d\n",cnt);
		for (i= 1;i<=cnt;i++)
		printf("%d%c",sta[i],i<cnt?' ':'\n');
	}return 0;
}
