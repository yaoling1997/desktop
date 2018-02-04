#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001;
struct edge{
	int to,h;
};
vector<edge> g[maxn];
int low[maxn],pre[maxn],b[maxn];
int n,m,i,x,y,time,top;
void dfs(int o,int fa){
	low[o]= pre[o]= ++time;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		edge e= g[o][i];
		int v= e.to,h= e.h;
		if (!pre[v]){
			dfs(v,h);
			low[o]= min(low[o],low[v]);
			if (low[v]>pre[o]) b[h]= 1;
		}else if (pre[v]<pre[o] && h!=fa)
			low[o]= min(low[o],pre[v]);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		g[x].push_back((edge){y,m});
		g[y].push_back((edge){x,m});
	}
	for (i= 1;i<=n;i++)
		if (!pre[i])
			dfs(i,-1);
	for (i= 1;i<=m;i++)
		if (b[i]) printf("%d ",i);
	return 0;
}
