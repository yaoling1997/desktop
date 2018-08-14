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
const int maxn= 5e5,M=26;
vector<int> g[maxn];
char s[maxn];
int c[maxn],vis[maxn],f[maxn][30],d[maxn];
int n,m,tim;
bool circle(){
	queue<int> Q;
	for (int i=1;i<=n;i++)
		if (!d[i])
			Q.push(i);
	while (!Q.empty()){
		int u=Q.front();
		Q.pop();
		for (int i=0;i<(int)g[u].size();i++){
			int v= g[u][i];
			d[v]--;
			if (!d[v])
				Q.push(v);
		}
	}
	for (int i=1;i<=n;i++)
		if (d[i])
			return true;
	return false;
}
void dfs(int o){
	if (vis[o])
		return;
	vis[o]=1;
	for (int i=0;i<(int)g[o].size();i++){
		int v= g[o][i];
		dfs(v);
		for (int j=1;j<=M;j++)
			f[o][j]= max(f[o][j],f[v][j]);
	}
	f[o][c[o]]++;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		c[i]=s[i]-'a'+1;
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		g[x].pb(y);
		d[y]++;
	}
	if (circle()){
		printf("-1");
	}else {
		memset(vis,0,sizeof(vis));
		int ans=0;
		for (int i=1;i<=n;i++){
			dfs(i);
			for (int j=1;j<=M;j++)
				ans= max(ans,f[i][j]);
		}
		printf("%d",ans);
	}
	return 0;
}
