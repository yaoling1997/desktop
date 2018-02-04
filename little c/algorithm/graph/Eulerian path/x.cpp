#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
const int maxn= 3001;
vector<int> edges;
vector<int> g[maxn];
int vis[maxn],d[maxn],b[maxn];
int n,m,S,s,cnt,top,i,x,y;
void addedge(int x,int y){
	edges.push_back(y);
	edges.push_back(x);
	int m= edges.size();
	g[x].push_back(m-2);
	g[y].push_back(m-1);
}
void dfs(int o){
	if (!b[o]) cnt++,b[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++)
		if (!vis[g[o][i]]){
			vis[g[o][i]]= vis[g[o][i]^1]= 1;
			dfs(edges[g[o][i]]);
		}
	d[++top]= o;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &m, &S);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		addedge(x,y);
		d[x]++;d[y]++;
	}
	for (i= 1;i<=n;i++)
		if (d[i]%2){
			s++;
			if (s>2) break;
		}
	if (s<=2)
		dfs(S);
	if (s>2 || cnt!=n) printf("no Euler path");
	else
		while (top)
			printf("%d ",d[top--]);
	return 0;
}
