#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
const int maxn= 1e5;
vector<int> g[maxn];
int f[maxn];
int n,m,i,x,ans;
void dfs(int o){
	f[o]= 0;
	vector<int> a;
	int lg= g[o].size(),i;
	if (!lg)
		return;
	for (i= 0;i<lg;i++){
		int v= g[o][i];
		dfs(v);
		a.pb(f[v]);
	}
	int la= a.size();
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	f[o]= a[0]+1;
	ans= max(ans,f[o]);
	if (la>1){
		ans= max(ans,a[0]+a[1]+2);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 2;i<=n;i++){
		scanf("%d",&x);
		g[x].pb(i);
	}
	for (i= 1;i<=m;i++)	{
		scanf("%d",&x);
		g[x].pb(n+i);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}

