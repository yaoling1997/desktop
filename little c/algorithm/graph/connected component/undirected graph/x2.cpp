#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn= 3001;
struct edge{
	int u,v;
};
vector<int> g[maxn],bcc[maxn];
edge stack[maxn];
int low[maxn],pre[maxn],cur[maxn],bccno[maxn],cut[maxn];
int la,x,y,n,m,i,j,time,cnt;
void dfs(int o,int fa){
	low[o]= pre[o]= ++time;
	int i,len= g[o].size(),child= 0;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		edge e= (edge){o,v};
		if (!pre[v]){
			stack[++la]= e;
			child++;
			dfs(v,o);
			low[o]= min(low[o],low[v]);
			if (low[v]>=pre[o]){
				cnt++;cut[o]= 1;
				while (true){
					edge x= stack[la--];
					if (bccno[x.u]!=cnt){
						bccno[x.u]= cnt;
						bcc[cnt].push_back(x.u);
					}
					if (bccno[x.v]!=cnt){
						bccno[x.v]= cnt;
						bcc[cnt].push_back(x.v);
					}
					if (x.u==e.u&&x.v==e.v) break;
				}
			}
		}else if (pre[v]<pre[o]&&v!=fa){
			low[o]= min(low[o],pre[v]);
			stack[++la]= e;
		}
	}
	if (fa<0 && child<=1) cut[o]= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (i= 1;i<=n;i++)
		if (!pre[i])
			dfs(i,-1);
	printf("%d\n",cnt);
	for (i= 1;i<=cnt;i++){
		sort(bcc[i].begin(),bcc[i].end());
		int len= bcc[i].size();
		for (j= 0;j<len;j++)
			printf("%d ",bcc[i][j]);
		printf("\n");
	}
	return 0;
}
