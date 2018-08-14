#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3100,oo= 1e8;
struct node{
	int v,s;
};
vector<int> g[maxn];
queue<node> Q;
int a[maxn][maxn],vis[maxn];
int X[maxn][maxn],Y[maxn][maxn];
int sta[10];
int n,m,i,j,x,y,now= -1,u,v,I,J,sum;
void bfs(int s){
	memset(vis,0,sizeof(vis));
	Q.push((node){s,0});
	vis[s]= 1;
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		int len= g[u.v].size(),i;
		for (i= 0;i<len;i++){
			int v= g[u.v][i];
			if (vis[v]) continue;
			vis[v]= 1;
			a[s][v]= u.s+1;
			Q.push((node){v,u.s+1});
		}
	}
}
bool cmp(int x,int y){
	return a[x][i]>a[y][i];
}
bool cmp2(int x,int y){
	return a[i][x]>a[i][y];
}
void update(int i,int u,int v,int j){
	int sum= a[i][u]+a[u][v]+a[v][j];
	if (sum>now){
		now= sum;
		sta[1]= i;
		sta[2]= u;
		sta[3]= v;
		sta[4]= j;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		g[x].push_back(y);
	}
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++){
			//a[i][j]= oo;
			if (i==j) a[i][j]= 0;
			X[i][j]= Y[i][j]= j;
		}
	for (i= 1;i<=n;i++)
		bfs(i);
	for (i= 1;i<=n;i++){
		sort(X[i]+1,X[i]+n+1,cmp);
		sort(Y[i]+1,Y[i]+n+1,cmp2);
	}
	for (u= 1;u<=n;u++)
		for (v= 1;v<=n;v++){
			//if (u==v||a[u][v]==oo) continue;
			if (!a[u][v]) continue;
			i= j= 1;
			if (X[u][i]==v) i++;
			if (Y[v][j]==u) j++;
			if (X[u][i]!=Y[v][j]){
				i= X[u][i];
				j= Y[v][j];
				if (!a[i][u]||!a[v][j]) continue;
				update(i,u,v,j);
			}else {
				I= i+1;J= j+1;
				if (X[u][I]==v) I++;
				if (Y[v][J]==u) J++;
				x= X[u][i];y= Y[v][J];
				if (a[x][u]&&a[v][y])
					update(x,u,v,y);
				x= X[u][I];y= Y[v][j];
				if (a[x][u]&&a[v][y])
					update(x,u,v,y);				
			}
		}
	for (i= 1;i<=4;i++)
		printf("%d%c",sta[i],i<4?' ':'\n');
	return 0;
}