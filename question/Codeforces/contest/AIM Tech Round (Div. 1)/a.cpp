#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 6e2;
vector<int> g[maxn];
int d[maxn],vis[maxn],a[maxn][maxn];
int n,m,i,j,x,y,z;
char C(int o){
	if (o==1) return 'a';
	if (o==2) return 'b';
	if (o==3) return 'c';
	return 'H';
}
void dfs(int o){
	vis[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (vis[v]) continue;
		dfs(v);
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
		d[x]++;
		d[y]++;
		a[x][y]= a[y][x]= 1;
	}
	for (i= 1;i<=n;i++)
		if (d[i]==n-1)
			vis[i]= 2;
	for (i= 1;i<=n;i++)
		if (!vis[i]){
			dfs(i);
			break;
		}
	for (i= 1;i<=n;i++)
		if (!vis[i])
			vis[i]= 3;
	bool bl= 1;
	for (i= 1;i<=n;i++){
		if (vis[i]==3){
			for (j= i+1;j<=n;j++)
				if (vis[j]==3&&!a[i][j]){
					bl= 0;
					break;
				}
		}
		if (vis[i]==1){
			for (j= i+1;j<=n;j++)
				if (vis[j]==1&&!a[i][j]){
					bl= 0;
					break;
				}
		}
		if (!bl) break;		
	}
	if (!bl){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for (i= 1;i<=n;i++)
		printf("%c",C(vis[i]));
	return 0;
}
