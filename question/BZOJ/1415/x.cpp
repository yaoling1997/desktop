#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
const int maxn= 2000;
struct node{
	int u,v;
};
vector<int> g[maxn];
double f[maxn][maxn];
int pos[maxn][maxn],vis[maxn];
int n,m,s,t,x,y,i,j;
void pre(int o){
	memset(vis,0,sizeof(vis));
	queue<node> Q;vis[o]= 1;pos[o][o]= o;
	int len= g[o].size(),i,j;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		vis[v]= 1;
		pos[o][v]= v;
		Q.push((node){v,v});
		f[o][v]= 1;
		for (j= 0;j<g[v].size();j++){
			int x= g[v][j];
			f[o][x]= 1;
		}
	}f[o][o]= 0;
	while (!Q.empty()){
		int u= Q.front().u,x= Q.front().v,len= g[u].size();
		Q.pop();
		for (i= 0;i<len;i++){
			int v= g[u][i];
			if (!vis[v]){
				vis[v]= 1;
				pos[o][v]= x;
				Q.push((node){v,x});
			}
		}
	}
}
double dfs(int s,int t){
	double &res= f[s][t];
	int i,len= g[t].size();
	if (res>=0) return res;
	res= 0;int next= pos[pos[s][t]][t];
	res+= dfs(next,t);	
	for (i= 0;i<len;i++){
		int v= g[t][i];
		res+= dfs(next,v);		
	}
	res+= len+1;
	res/= len+1;
	return res;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	scanf("%d %d",&s, &t);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			f[i][j]= -1;
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (i= 1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
		pre(i);
	}
	dfs(s,t);
	printf("%.3lf",f[s][t]);
	return 0;
}
