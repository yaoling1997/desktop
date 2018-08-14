#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 6e5;
priority_queue<int> Q[maxn];
vector<int> g[maxn];
int d[maxn],X[maxn],D[maxn];
int x,y,n,i,j,ans,cnt;
void dfs(int o,int fa,int u,int dep){
	d[o]= dep;X[o]= u;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa) continue;
		dfs(v,o,u,dep+1);
	}
}
bool cmp(int a,int b){
	return Q[a].size()<Q[b].size();
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<n;i++){
		scanf("%d%d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
		D[x]++;
		D[y]++;
	}
	d[1]= 1;
	int len= g[1].size();
	for (i= 0;i<len;i++){
		int v= g[1][i];
		dfs(v,1,v,2);
	}
	for (i= 2;i<=n;i++)
		if (D[i]==1)
			Q[X[i]].push(d[i]);
	sort(g[1].begin(),g[1].end(),cmp);
	while (1){
		cnt++;
		for (i= len-1;i>=0;i--){
			int v= g[1][i];
			if (Q[v].empty()) break;
		}
		if (i==len-1) break;
		for (j= i+1;j<len;j++){
			int v= g[1][j];
			ans= max(ans,Q[v].top()-2+cnt);
			Q[v].pop();
		}
	}printf("%d",ans);
	return 0;
}
