#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001;
vector<int> g[maxn],node[maxn];
int par[maxn],cover[maxn];
int T,ans,S,K,x,y,i,j,n;
void init(int n){
	ans= 0;
	for (int i= 1;i<=n;i++)
		g[i].clear(),
			node[i].clear(),
			cover[i]= 0;
}
void dfs(int o,int fa,int d){
	par[o]= fa;
	int len= g[o].size(),i;
	if (len==1&&d>K) node[d].push_back(o);
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v!=fa)
			dfs(v,o,d+1);
	}
}
void dfs1(int o,int fa,int d){
	cover[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v!=fa&&d<K)
			dfs1(v,o,d+1);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d",&n);
		init(n);
		scanf("%d %d",&S, &K);
		for (i= 1;i<n;i++){
			scanf("%d %d",&x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(S,0,0);
		for (i= n-1;i>K;i--){
			int len= node[i].size();
			if (len)
				for (j= 0;j<len;j++){
					int v= node[i][j];
					if (!cover[v]){
						ans++;
						int cnt= 0;
						while (cnt<K){
							cnt++;
							v= par[v];
						}
						dfs1(v,0,0);
					}
				}
		}printf("%d\n",ans);
	}return 0;
}
