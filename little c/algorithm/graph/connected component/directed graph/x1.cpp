#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn= 3001;
int head[maxn],next[maxn],des[maxn];
int pre[maxn],low[maxn],stack[maxn],sccno[maxn];
vector<int> scc[maxn];
int n,m,x,y,i,j,top,cnt,la,time;
void dfs(int o){
	pre[o]= low[o]= ++time;
	stack[++la]= o;
	for (int p= head[o];p;p= next[p]){
		int v= des[p];
		if (!pre[v]){
			dfs(v);
			low[o]= min(low[o],low[v]);
		}else if (!sccno[v])//反向边更新
			low[o]= min(low[o],pre[v]);
	}
	if (low[o]==pre[o]){
		cnt++;
		for (;;){
			int x= stack[la--];
			scc[cnt].push_back(x);
			sccno[x]= cnt;
			if (x==o) break;
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		top++;
		des[top]= y;
		next[top]= head[x];
		head[x]= top;
	}
	for (i= 1;i<=n;i++)
		if (!pre[i]) dfs(i);
	printf("%d\n",cnt);
	for (i= 1;i<=cnt;i++){
		int len= scc[i].size();
		for (j= 0;j<len;j++)
			printf("%d ",scc[i][j]);
		printf("\n");
	}
	return 0;
}
