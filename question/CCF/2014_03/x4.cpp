#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const ll maxn= 500;
typedef pair<ll,ll> PA;
vector<ll> g[maxn];
queue<PA> Q;
ll f[maxn][maxn];
ll X[maxn],Y[maxn];
ll n,m,k,r,i,N;
ll sqr(ll x){
	return x*x;
}
bool ok(ll i,ll j){
	ll d2= sqr(X[i]-X[j])+sqr(Y[i]-Y[j]);
	return d2<=r*r;
}
void bfs(ll s,ll t){
	memset(f,-1,sizeof(f));
	f[s][0]= 0;
	Q.push(mp(s,0));
	while (!Q.empty()){
		PA u= Q.front();
		Q.pop();
		ll len= g[u.first].size();
		ll i;
		for (i= 0;i<len;i++){
			ll v= g[u.first][i];
			if (v>n){
				if (f[v][u.second+1]!=-1)
					continue;
				if (u.second+1>k)
					continue;
				f[v][u.second+1]= f[u.first][u.second]+1;
				Q.push(mp(v,u.second+1));
			}else {
				if (f[v][u.second]!=-1)
					continue;
				f[v][u.second]= f[u.first][u.second]+1;
				Q.push(mp(v,u.second));
			}
		}
	}
}
void solve(){
	ll i,j;
	for (i= 1;i<=N;i++)
		for (j= i+1;j<=N;j++){
			if (ok(i,j)){
				g[i].pb(j);
				g[j].pb(i);				
			}
		}
	bfs(1,2);
	ll ans= 1000;
	for (i= 0;i<=k;i++){
		if (f[2][i]<0)
			continue;
		ans= min(ans,f[2][i]);
	}
	cout<<ans-1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>n>>m>>k>>r;
	N= n+m;
	for (i= 1;i<=n;i++){
		cin>>X[i]>>Y[i];
	}
	for (i= 1;i<=m;i++){
		cin>>X[n+i]>>Y[n+i];
	}
	solve();
	return 0;
}

