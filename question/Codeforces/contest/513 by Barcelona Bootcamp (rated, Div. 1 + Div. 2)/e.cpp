#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
vector<int> g[maxn];
int f[maxn],s[maxn];
ll ans;
int n;
void dfs(int o,int fa,int d){
	s[o]=1;
	f[d]++;
	int len= g[o].size();
	for (int i=0;i<len;i++){
		int v=g[o][i];
		if (v==fa)
			continue;
		dfs(v,o,d^1);
		s[o]+=s[v];
	}
	ans+=(ll)s[o]*(n-s[o]);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0,0);
	ans+=(ll)f[0]*f[1];
	ans>>=1;
	printf("%I64d",ans);
	return 0;
}
