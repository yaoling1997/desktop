#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 500;
struct node{
	int v,s;
};
queue<node> Q;
int a[maxn][maxn];
int vis[maxn];
int n,m,i,j,x,y,z,d1,d2;
int bfs(int o){
	while (!Q.empty()) Q.pop();
	memset(vis,0,sizeof(vis));
	Q.push((node){1,0});
	vis[1]= 1;
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		for (int i= 1;i<=n;i++)
			if (a[u.v][i]==o&&!vis[i]){
				if (i==n) return u.s+1;
				vis[i]= 1;
				Q.push((node){i,u.s+1});
			}
	}return -1;
}
int main()
{
	scanf("%d%d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		a[x][y]= a[y][x]= 1;
	}
	d1= bfs(0);
	d2= bfs(1);
	if (d1==-1||d2==-1)
		printf("-1");
	else printf("%d",max(d1,d2));
	return 0;
}
