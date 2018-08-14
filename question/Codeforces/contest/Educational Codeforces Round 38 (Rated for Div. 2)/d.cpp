#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
struct node{
	int v;
	ll c;
	bool operator <(const node a)const{
		return c>a.c;
	}
};
priority_queue<node> Q;
bool done[maxn];
ll a[maxn],w[maxn],d[maxn];
int h[maxn],des[maxn],nex[maxn];
int n,m,tot;
void addEdge(int u,int v,ll cost){
	tot++;
	nex[tot]= h[u];
	des[tot]= v;
	w[tot]= cost;
	h[u]= tot;
}
void solve(){
	for (int i= 1;i<=n;i++){
		Q.push((node){i,a[i]});
		d[i]=a[i];
	}
	while (!Q.empty()){
		node u= Q.top();
		Q.pop();
		if (done[u.v])
			continue;
		done[u.v]=1;
		for (int i=h[u.v];i;i=nex[i]){
			int v= des[i];
			if (d[v]>d[u.v]+2*w[i]){
				d[v]= d[u.v]+2*w[i];
				Q.push((node){v,d[v]});
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i= 1;i<=m;i++){
		int x,y;
		ll z;
		scanf("%d%d%I64d",&x, &y, &z);
		addEdge(x,y,z);
		addEdge(y,x,z);		
	}
	for (int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	solve();
	for (int i=1;i<=n;i++)
		printf("%I64d%c",d[i],i<n?' ':'\n');
	return 0;
}
