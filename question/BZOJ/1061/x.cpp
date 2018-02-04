#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll int
using namespace std;
const ll maxn= 1200,maxm= 11000,oo= 1e9;
struct edge{
	ll from,to,cap,flow,cost;
};
vector<edge> edges;
vector<int> g[maxn];
ll vis[maxn],d[maxn],p[maxn],a[maxn];
ll A[maxn][maxm],B[maxm],C[maxm],P[maxm];
ll n,m,x,y,z,i,j,s,t,tot,flow,cost;
void addedge(ll from,ll to,ll cap,ll cost){
	edges.push_back((edge){from,to,cap,0,cost});
	edges.push_back((edge){to,from,0,0,-cost});
	ll m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool spfa(){
	ll i;
	for (i= 1;i<=tot;i++) d[i]= oo;
	d[s]= 0;a[s]= oo;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()){
		ll u= Q.front(),len= g[u].size(),i;
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
	ll u= t;
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
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		A[i][m+1]= x;
	}
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &P[i]);
		if (x>y) swap(x,y);
		for (j= x;j<=y;j++)	A[j][i]= 1;
	}
	for (i= n+1;i>0;i--)
		for (j= 1;j<=m+1;j++)
			A[i][j]-= A[i-1][j];
	for (i= 1;i<=n+1;i++)
		for (j= 1;j<=m;j++)
			if (A[i][j]==1) B[j]= i;
			else if (A[i][j]==-1) C[j]= i;
	s= n+2;t= s+1;tot= t;
	for (i= 1;i<=n+1;i++)
		if (A[i][m+1]>0) addedge(s,i,A[i][m+1],0);
		else if (A[i][m+1]<0) addedge(i,t,-A[i][m+1],0);
	for (i= 1;i<=m;i++)
		addedge(B[i],C[i],oo,P[i]);
	for (i= 2;i<=n+1;i++)
		addedge(i,i-1,oo,0);
	while (spfa());
	printf("%d",cost);
	return 0;
}
