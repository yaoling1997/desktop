#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 1e3+10;
int h[maxn],des[maxn*2],nex[maxn*2];
int ds[maxn],dt[maxn],a[maxn][maxn];
int n,m,s,t,tot,ans;
void addedge(int u,int v){
	nex[++tot]=h[u];
	des[tot]=v;
	h[u]=tot;
}
void bfs(int s,int *d){
	for (int i=1;i<=n;i++)
		d[i]=-1;
	d[s]=0;
	queue<int>Q;
	Q.push(s);
	while (!Q.empty()){
		int u=Q.front();
		Q.pop();
		for (int i=h[u];i;i=nex[i]){
			int v= des[i];
			if (d[v]==-1){
				d[v]=d[u]+1;
				Q.push(v);
			}
		}
	}
}
bool ok(int u,int v){
	if (a[u][v])
		return false;
	int nd=min(ds[u]+dt[v]+1,ds[v]+dt[u]+1);
	return nd>=ds[t];
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d%d",&n, &m, &s, &t);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		a[x][y]=a[y][x]=1;
		addedge(x,y);
		addedge(y,x);
	}
	bfs(s,ds);
	bfs(t,dt);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (ok(i,j))
				ans++;
	printf("%d",ans);
	return 0;
}
