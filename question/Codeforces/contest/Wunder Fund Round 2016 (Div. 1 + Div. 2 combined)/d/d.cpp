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
ll d[maxn],a[maxn];
ll n,X,Y,x,y,i,bl,now,ans;
void dfs(ll o,ll fa){
	ll len= g[o].size(),i;
	int left= 2;
	for (i= 0;i<len;i++){
		ll v= g[o][i];
		if (v==fa) continue;
		dfs(v,o);
		if (left>0&&a[v])
			ans++,left--;
	}
	a[o]= left>0;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld%lld%lld",&n, &X, &Y);
	for (i= 1;i<n;i++){
		scanf("%lld%lld",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (i= 1;i<=n;i++){
		d[i]= g[i].size();
		if (d[i]==n-1) bl= 1;
	}
	if (X>Y){
		if (bl) printf("%lld",X+(n-2)*Y);
		else printf("%lld",(n-1)*Y);
	}else if (X==Y){
		printf("%lld",(n-1)*Y);
	}else {
		dfs(1,0);
		printf("%lld",ans*X+(n-1-ans)*Y);
	}
}
