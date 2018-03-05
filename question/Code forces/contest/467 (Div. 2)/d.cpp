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
vector<int> g[maxn];
queue<int> Q;
int vis[maxn][2];
int sta[maxn],d[maxn];
int b[maxn],done[maxn],pre[maxn];
int n,m,s,ans,la,circle,tim;
void dfs(int o,int t){
	if (vis[o][t]){
		return;
	}
	vis[o][t]=1;
	int len= g[o].size();
	if (len==0&&t==0){
		ans=1;
		sta[++la]=o;
	}else {
		for (int i=0;i<len;i++){
			int v= g[o][i];
			dfs(v,t^1);
			if (ans){
				sta[++la]=o;
				return;
			}
		}
	}
}
void dfsCircle(int o){
	pre[o]=++tim;
	int len= g[o].size();
	for (int i=0;i<len;i++){
		int v= g[o][i];
		if (done[v])
			continue;
		if (!pre[v]){
			dfsCircle(v);
			if (ans==1)
				return;
		}else{
			ans=1;
			return;
		}
	}
	done[o]=1;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d",&x);
		for (int j=1;j<=x;j++){
			scanf("%d",&y);
			g[i].pb(y);
			d[y]++;
		}
	}
	scanf("%d",&s);
	dfs(s,1);
	if (ans){
		printf("Win\n");
		for (int i=la;i>0;i--)
			printf("%d%c",sta[i],i>1?' ':'\n');
	}else {
		dfsCircle(s);
		printf("%s",ans?"Draw":"Lose");
	}
	return 0;
}
