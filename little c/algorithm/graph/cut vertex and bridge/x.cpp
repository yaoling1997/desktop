#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 3001;
int head[maxn],next[maxn],des[maxn];
int pre[maxn],cut[maxn],low[maxn];
int n,m,i,x,y,time,top;
void dfs(int o,int fa){
	low[o]= pre[o]= ++time;
	int p= head[o],child= 0;
	while (p){
		int v= des[p];
		if (!pre[v]){
			child++;
			dfs(v,o);
			low[o]= min(low[o],low[v]);
			if (low[v]>=pre[o])	cut[o]= 1;
		}else if (pre[v]<pre[o] && v!=fa)
			low[o]= min(low[o],pre[v]);
		p= next[p];
	}
	if (fa<0 && child==1) cut[o]= 0;
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
		top++;
		des[top]= x;
		next[top]= head[y];
		head[y]= top;
	}
	for (i= 1;i<=n;i++)
		if (!pre[i])
			dfs(i,-1);
	for (i= 1;i<=n;i++)
		if (cut[i])
			printf("%d ",i);
	return 0;
}
