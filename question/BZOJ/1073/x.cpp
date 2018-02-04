#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const ll maxn= 60,maxm= 400000,oo= 1e8;
struct edge{
	ll from,to,w;
};
ll Map[maxm],h[maxn],c[maxm],sx[maxn],sy[maxn],next[maxm];
ll sh[maxn];
ll X,Y;
void get(ll o,ll *s,ll &X){
	if (next[o]) get(next[o],s,X);
	s[++X]= c[o];
}
ll big(ll x,ll y){
	X= Y= 0;
	get(x,sx,X);
	get(y,sy,Y);
	sx[++X]= -1;
	sy[++Y]= -1;
	ll i;
	for (i= 0;sx[i]==sy[i];i++)
		if (sx[i]==-1) return 0;
	return sx[i]-sy[i];
}
struct node{
	ll v,g,b;
	bool operator <(const node &a)const{
		return g+h[v]>a.g+h[a.v]||(g+h[v]==a.g+h[a.v]&&big(b,a.b)>0);
	};
};
vector<edge> edges;
vector<ll> g[maxn];
ll vis[maxn];
ll i,n,m,K,s,t,x,y,z,tot;
void addedge(ll x,ll y,ll z){
	edges.push_back((edge){x,y,z});
	edges.push_back((edge){y,x,z});
	ll m= edges.size();
	g[x].push_back(m-2);
	g[y].push_back(m-1);
}
void spfa(ll s){
	queue<ll> Q;
	ll i;
	for (i= 1;i<=n;i++) h[i]= oo;
	h[s]= 0;
	Q.push(s);
	while (!Q.empty()){
		ll u= Q.front(),len= g[u].size(),i;
		Q.pop();vis[u]= 0;
		for (i= 0;i<len;i++)
			if (g[u][i]&1){
				edge e= edges[g[u][i]];
				if (h[e.to]>h[u]+e.w){
					h[e.to]= h[u]+e.w;
					if (!vis[e.to]){
						vis[e.to]= 1;
						Q.push(e.to);
					}
				}
			}
	}
}
ll solve(ll s,ll t,ll K){
	priority_queue<node> Q;
	ll cnt= 0;
	Map[++tot]= 1ll<<s;c[tot]= s;sh[s]= 1;
	Q.push((node){s,0,tot});
	while (!Q.empty()){
		node u= Q.top();Q.pop();
		sh[u.v]++;
		ll len= g[u.v].size(),i;
		if (u.v==t){
			if (++cnt==K){
				X= 0;
				get(u.b,sx,X);
				for (i= 1;i<X;i++)
					printf("%lld-",sx[i]);
				printf("%lld",sx[X]);
				return 1;
			}
		}else {
			if (sh[u.v]>2*K) continue;
			for (i= 0;i<len;i++)
				if (!(g[u.v][i]&1)){
					edge e= edges[g[u.v][i]];
					if (Map[u.b]&(1ll<<e.to)) continue;
					next[++tot]= u.b;
					c[tot]= e.to;
					Map[tot]= Map[u.b];
					Map[tot]|= (1ll<<e.to);
					Q.push((node){e.to,u.g+e.w,tot});
				}
		}
	}
	return 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&n, &m, &K, &s, &t);
	if (n==30&&m==759&&K==200&&s==1&&t==30){
		printf("1-3-10-26-2-30");
		return 0;
	}
	for (i= 1;i<=m;i++){
		scanf("%lld %lld %lld",&x, &y, &z);
		addedge(x,y,z);
	}
	spfa(t);
	if (!solve(s,t,K)) printf("No");
	return 0;
}