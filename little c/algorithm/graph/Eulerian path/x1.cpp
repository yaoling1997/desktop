#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
const int maxn= 3001;
vector<int> edges;
vector<int> g[maxn];
int d[maxn],d1[maxn],d2[maxn],p[2],b[maxn],vis[maxn];
int n,m,S,x,y,i,top,bl,cnt;
void addedge(int x,int y){
	edges.push_back(y);
	g[x].push_back(edges.size()-1);
}
void dfs(int o){
	if (!b[o]) b[o]= 1,cnt++;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int e= g[o][i];
		if (!vis[e]){
			vis[e]= 1;
			dfs(edges[e]);
		}
	}
	d[++top]= o;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d %d %d",&n, &m, &S);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		addedge(x,y);
		d1[x]++;d2[y]++;
	}
	for (i= 1;i<=n;i++)
		if (d1[x]!=d2[y]){
			if (top==3){top++;break;}
			p[top++]= i;
		}
	bl= 0;
	if (top==2 && (d1[p[0]]-d2[p[0]])*(d1[p[1]]-d2[p[1]])==-1) bl= 1;
	if (!top) bl= 1;
	top= 0;
	if (bl)
		dfs(S);
	if (!bl || cnt!=n) printf("no Eulerian path");
	else while (top)
			 printf("%d ",d[top--]);
	return 0;
}
