#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 2000;
vector<int> g[maxn];
vector<int> a[maxn];
int c[maxn],stack[maxn];
int n,B,x,y,tot,i;
void dfs(int o,int fa){
	int i,j;
	for (i= 0;i<g[o].size();i++){
		int v= g[o][i];
		if (v==fa) continue;
		dfs(v,o);
		for (j= 0;j<a[v].size();j++)
			a[o].push_back(a[v][j]);
		a[v].clear();
		if (a[o].size()>=B){
			stack[++tot]= o;
			for (j= 0;j<a[o].size();j++){
				int v= a[o][j];
				c[v]= tot;
			}a[o].clear();
		}
	}a[o].push_back(o);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &B);
	for (i= 1;i<n;i++){
		scanf("%d %d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}dfs(1,0);
	for (i= 0;i<a[1].size();i++){
		int v= a[1][i];
		c[v]= tot;
	}
	printf("%d\n",tot);
	for (i= 1;i<=n;i++) printf("%d ",c[i]);
	printf("\n");
	for (i= 1;i<=tot;i++)
		printf("%d ",stack[i]);
	return 0;
}
