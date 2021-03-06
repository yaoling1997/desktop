#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 1e6;
struct line{
	int x,y,z;
}L[maxn];
struct edge{
	int v,w;
};
vector<int> bcc[maxn];
vector<edge> g[maxn];
int head[maxn],next[maxn],des[maxn],bccno[maxn];
int pre[maxn],low[maxn],vis[maxn],cut[maxn];
int bv[maxn],dv[maxn];
int n,m,i,j,x,y,z,top,tim,cnt,s,t,bl,S,T;
void dfs(int o,int fa){
	pre[o]= low[o]= ++tim;
	int p= head[o];
	while (p){
		int v= des[p];
		if (!pre[v]){
			dfs(v,p|1);
			low[o]= min(low[o],low[v]);
			if (low[v]>pre[o])
				cut[p]= cut[p^1]= 1;
		}else if (pre[v]<pre[o] && (p|1)!=fa)
			low[o]= min(low[o],pre[v]);
		p= next[p];
	}
}
void dfs1(int o){
	vis[o]= 1;
	bccno[o]= cnt;
	bcc[cnt].push_back(o);
	int p= head[o];
	while (p){
		if (!cut[p]){
			int v= des[p];
			if (!vis[v]) dfs1(v);
		}
		p= next[p];
	}
}
void DFS(int o,int now){	
	vis[o]= 1;
	now|= dv[o];
	if (o==T){
		bl= now;
		return;
	}
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		if (vis[g[o][i].v]) continue;
		DFS(g[o][i].v,g[o][i].w|now);
	}
}
bool get(){
	S= bccno[s];
	T= bccno[t];
	if (S==T&&dv[S]) return 1;
	bl= 0;
	memset(vis,0,sizeof(vis));
	DFS(S,0);
	return bl;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	top= 1;
	for (i= 1;i<=m;i++){
		scanf("%d%d%d",&x, &y, &z);
		L[i]= (line){x,y,z};
		top++;
		des[top]= y;
		next[top]= head[x];
		head[x]= top;
		top++;
		des[top]= x;
		next[top]= head[y];
		head[y]= top;
	}scanf("%d%d",&s, &t);
	for (i= 1;i<=n;i++)
		if (!pre[i])
			dfs(i,-1);
	for (i= 1;i<=n;i++)
		if (!vis[i]){
			cnt++;
			dfs1(i);
		}
	for (i= 1;i<=m;i++){
		x= bccno[L[i].x];
		y= bccno[L[i].y];
		z= L[i].z;
		if (x==y){
			dv[x]|= z;
		}else {
			g[x].push_back((edge){y,z});
			g[y].push_back((edge){x,z});
		}
	}
	if (get()) printf("YES\n");
	else printf("NO\n");
	return 0;
}