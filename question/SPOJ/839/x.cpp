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
const int maxn= 6e2,maxm= 4e3,oo= 1e9;
struct line{
	int u,v;
}L[maxm];
struct edge{
	int from,to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
queue<int> Q;
int ans[maxn],sta[maxn],stv[maxn],V[maxn];
int vis[maxn],d[maxn],cur[maxn],b[maxn];
int T,i,j,x,y,z,n,m,K,Max,s,t,cnt,p,la,flow,ooo;
void addedge(int from,int to,int cap){
	edges.push_back((edge){from,to,cap,0});
	edges.push_back((edge){to,from,0,0});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);	
}
bool bfs(){
	int i;
	/*for (i= 0;i<=t;i++)
	  vis[i]= 0;*/
	memset(vis,0,sizeof(vis));
	Q.push(s);
	vis[s]= 1;
	d[s]= 0;
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size();
		Q.pop();
		for (i= 0;i<len;i++){
			edge e= edges[g[u][i]];
			if (!vis[e.to]&&e.cap>e.flow){
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
		if (d[e.to]==d[o]+1 && (f= dfs(e.to,min(e.cap-e.flow,re)))>0){
			e.flow+= f;
			edges[g[o][i]^1].flow-= f;
			flow+= f;
			re-= f;
			if (!re) break;
		}
	}return flow;
}
void find(int o){
	b[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		edge e= edges[g[o][i]];
		if (b[e.to]||e.cap-e.flow==0) continue;
		find(e.to);
	}
}
void init(){
	memset(ans,0,sizeof(ans));
	flow= 0;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
 	scanf("%d",&T);
	for (int tt= 1;tt<=T;tt++){
		scanf("%d%d",&n, &m);
		init();
		for (i= 1;i<=m;i++){
			scanf("%d%d",&x, &y);
			L[i]= (line){x,y};
		}
		scanf("%d",&K);
		Max= 0;
		for (i= 1;i<=K;i++){
			scanf("%d%d",&x, &y);
			//ans[x]= y;
			sta[i]= x;
			stv[i]= y;
			V[i]= y;
			Max= max(Max,stv[i]);
		}
		s= n+1;t= n+2;
		p= 1;
		cnt= 0;
		while (Max){
			cnt++;
			Max>>= 1;
		}
		while (cnt--){
			edges.clear();
			for (i= 0;i<=t;i++)
				g[i].clear();
			for (i= 1;i<=m;i++){
				int u= L[i].u;
				int v= L[i].v;
				addedge(u,v,1);
				addedge(v,u,1);
			}
			for (i= 1;i<=K;i++){
				x= sta[i];
				y= stv[i];
				if (y&1)
					addedge(s,x,oo);
				else 
					addedge(x,t,oo);				
			}
			while (bfs()){
				/*for (i= 1;i<=t;i++)
				  cur[i]= 0;*/
				memset(cur,0,sizeof(cur));
				flow+= dfs(s,oo)*p;
				//dfs(s,oo);
			}
			/*for (i= 1;i<=t;i++)
			  b[i]= 0;*/
			memset(b,0,sizeof(b));
			find(s);
			for (i= 1;i<=n;i++)
				if (b[i]) ans[i]+= p;			
			p<<= 1;
			for (i= 1;i<=K;i++)
				stv[i]>>= 1;
		}
		for (i= 1;i<=n;i++)
		  printf("%d\n",ans[i]);
		/*ooo= 0;
		for (i= 1;i<=m;i++)
			ooo+= ans[L[i].u]^ans[L[i].v];
		if (ooo!=flow){
			printf("shit!");
			return 0;
			}*/
		/*for (i= 1;i<=K;i++)
			if (V[i]!=ans[sta[i]]){
				printf("shit!");
				return 0;
				}*/
		//printf("%d\n",flow);
	}
	//printf("ok");
	return 0;
}
