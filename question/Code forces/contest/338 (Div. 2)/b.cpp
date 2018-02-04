#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 3e5;
vector<ll> g[maxn];
ll d[maxn],f[maxn],F[maxn],vis[maxn];
ll ans;
ll n,m,i,j,x,y,tim;
void go(ll o,ll *f,ll p){
	if (vis[o]==tim) return;
	vis[o]= tim;
	ll &re= f[o],len= g[o].size(),i;
	re= 1;
	for (i= 0;i<len;i++){
		ll v= g[o][i];
		if (o*p>v*p){
			go(v,f,p);
			re= max(re,f[v]+1);
		}
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld%lld",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%lld%lld",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
		d[x]++;
		d[y]++;
	}
	tim++;
	for (i= 1;i<=n;i++){
		go(i,f,1);
		ans= max(ans,f[i]*d[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
