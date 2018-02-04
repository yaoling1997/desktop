#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn= 300,oo= 1e5;
int w[maxn][maxn],vis[maxn];
int pre[maxn],iw[maxn],cid[maxn],removed[maxn];
int ans,s,i,j,x,y,z,n,m,max_cid;
int dfs(int o){
	vis[o]= 1;int re= 1,i;
	for (i= 1;i<=n;i++)
		if (!vis[i]&&w[o][i]!=oo)
			re+= dfs(i);
	return re;
}
void update(int u){
	iw[u]= oo;
	for (int i= 1;i<=n;i++)
		if (!removed[i]&&iw[u]>w[i][u])
			iw[u]= w[i][u],pre[u]= i;
}
bool cycle(int u){
	max_cid++;
	int v= u;
	while (cid[v]!=max_cid){
		cid[v]= max_cid;
		v= pre[v];
	}
	return u==v;
}
bool get(int s){
	memset(vis,0,sizeof(vis));
	if (dfs(s)!=n) return 0;
	memset(cid,0,sizeof(cid));
	memset(removed,0,sizeof(removed));
	int i,u;
	for (i= 1;i<=n;i++)
		update(i);
	iw[s]= 0;pre[s]= s;
	ans= max_cid= 0;
	for (;;){
		int bl= 0;
		for (u= 1;u<=n;u++)
			if (u!=s&&!removed[u]&&cycle(u)){
				int v= u;
				bl= 1;
				do {
					if (u!=v) removed[v]= 1;
					ans+= iw[v];
					for (i= 1;i<=n;i++)
						if (!removed[i]&&cid[i]!=cid[u]){
							if (w[i][v]!=oo)
								w[i][u]= min(w[i][u],w[i][v]-iw[v]);
							w[u][i]= min(w[u][i],w[v][i]);
							if (pre[i]==v) pre[i]= u;
						}
					v= pre[v];
				}while (u!=v);
				update(u);
				break;
			}
		if (!bl) break;
	}
	for (i= 1;i<=n;i++)
		if (!removed[i])
			ans+= iw[i];
	return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			w[i][j]= oo;
	for (i= 1;i<=m;i++){
		scanf("%d%d%d",&x, &y, &z);
		if (x==y) continue;
		w[x][y]= min(w[x][y],z);
	}
	if (get(1)) printf("%d",ans);
	else printf("no solution!");
	return 0;
}
