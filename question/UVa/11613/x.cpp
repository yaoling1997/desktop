#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const ll maxn= 300,oo= 1e9;
struct edge{
	ll from,to,cap,flow,cost;
};
vector<edge> edges;
vector<ll> g[maxn];
queue<ll> Q;
ll vis[maxn],a[maxn],p[maxn],d[maxn];
ll mm,nn,pp,ss,EE;
ll T,M,I,i,j,s,t,flow,cost;
void init(){
	flow= cost= 0;
	ll i;
	edges.clear();
	for (i= 1;i<=t;i++) g[i].clear();
	s= 2*M+1;t= s+1;
}
void addedge(ll from,ll to,ll cap,ll cost){
	edges.push_back((edge){from,to,cap,0,cost});
	edges.push_back((edge){to,from,0,0,-cost});
	ll m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
bool spfa(){
	ll i;
	for (i= 1;i<=t;i++)
		d[i]= -oo,vis[i]= 0;	
	d[s]= 0;	
	a[s]= oo;
	Q.push(s);
	while (!Q.empty()){
		ll u= Q.front(),len= g[u].size();
		Q.pop();vis[u]= 0;
		for (i= 0;i<len;i++){
			edge &e= edges[g[u][i]];
			if (d[e.to]<d[u]+e.cost&&e.cap>e.flow){
				d[e.to]= d[u]+e.cost;
				a[e.to]= min(a[u],e.cap-e.flow);
				p[e.to]= g[u][i];
				if (!vis[e.to]){
					vis[e.to]= 1;
					Q.push(e.to);
				}
			}
		}
	}
	if (d[t]<=0) return 0;
	flow+= a[t];
	cost+= a[t]*d[t];
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
	scanf("%lld",&T);
	for (ll TT= 1;TT<=T;TT++){
		scanf("%lld%lld",&M, &I);
		init();
		for (i= 1;i<=M;i++){
			scanf("%lld%lld%lld%lld%lld",&mm,&nn,&pp,&ss,&EE);
			addedge(s,i,nn,-mm);
			addedge(i+M,t,ss,pp);
			for (j= 0;j<=EE;j++){
				if (i+j>M) break;
				addedge(i,i+M+j,+oo,-I*j);
			}
		}
		while (spfa());
		printf("Case %lld: %lld\n",TT, cost);
	}return 0;
}
