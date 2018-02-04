#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn= 50001;
struct edge{
	int u,v;
};
edge a[maxn],b[maxn];
vector<int> g[maxn],h[maxn];
int sccno[maxn],pre[maxn],low[maxn],d[maxn],vis[maxn],stack[maxn];
int scc[maxn];
int n,m,i,j,top,time,la,cnt,bb,total,head;
bool operator !=(edge a,edge b){return a.u!=b.u || a.v!=b.v;}
bool cmp(edge a,edge b){return a.u<b.u || (a.u==b.u && a.v<b.v);}
void dfs(int o){
	low[o]= pre[o]= ++time;stack[++la]= o;
	int len= g[o].size();
	for (int i= 0;i<len;i++){
		int v= g[o][i];
		if (!pre[v]){
			dfs(v);
			low[o]= min(low[o],low[v]);
		}else if (!sccno[v] && pre[v]<=pre[o])
			low[o]= min(low[o],pre[v]);
	}
	if (low[o]==pre[o]){
		cnt++;
		while (true){
			int x= stack[la--];
			sccno[x]= cnt;
			if (x==o) break;
		}
	}
}
void find(int o){
	vis[o]= 1;total+= scc[o];int len= h[o].size();
	for (int i= 0;i<len;i++){
		int v= h[o][i];
		if (!vis[v])
			find(v);
	}
}
bool check(int o){
	find(o);
	return !(total-n);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++)
		scanf("%d %d",&a[i].u, &a[i].v);
	sort(a+1,a+m+1,cmp);
	for (i= 1;i<=m;i++)
		if (a[i]!=a[i-1]) b[++top]= a[i];
	for (i= 1;i<=top;i++)
		g[b[i].u].push_back(b[i].v);
	for (i= 1;i<=n;i++)
		if (!pre[i])
			dfs(i);
	for (i= 1;i<=n;i++){
		int u= sccno[i],len= g[i].size();
		scc[u]++;
		for (j= 0;j<len;j++){
			int v= sccno[g[i][j]];
			if (u==v) continue;
			h[v].push_back(u);
			d[u]++;
		}
	}
	for (i= 1;i<=cnt;i++)
		if (!d[i]) {
			bb++;
			head= i;
			if (bb==2) break;
		}
	if (bb==2) 
		printf("0");
	else if (check(head)) printf("%d\n",scc[head]);
	else printf("0");
	return 0;
}
