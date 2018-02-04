#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 10001;
vector<int> g[maxn];
queue<int> Q;
int w[maxn],d[maxn],sh[maxn],vis[maxn];
int n,m,i,j,x,y,now,top,u;
bool cmp(int a,int b){
	return w[a]<w[b];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++) scanf("%d",&w[i]);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		g[y].push_back(x);d[x]++;
	}
	for (i= 1;i<=n;i++){
		if (!d[i]) Q.push(i);
		sh[i]= i;
	}
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();
		for (i= 0;i<len;i++){
			int v= g[u][i];
			d[v]--;w[v]= min(w[v],w[u]-1);
			if (!d[v]) Q.push(v);
		}
	}sort(sh+1,sh+n+1,cmp);
	for (i= 1;i<=n;i++) printf("%d%c",sh[i],i<n?' ':'\n');
	for (i= 1;i<=n;i++){
		Q.push(i);now= top= 0;
		while (!Q.empty()){
			int u= Q.front(),len= g[u].size(),j;
			Q.pop();
			if (vis[u]==i) continue;
			vis[u]= i;now++;
			for (j= 0;j<len;j++)
				Q.push(g[u][j]);
		}
		for (j= 1;j<=n;j++)
			if (vis[u= sh[j]]!=i){
				if (w[u]<=now) now++;
				else {
					if (now+top<w[u]) top++;
					else now+= top+1,top= 0;
				}
			}printf("%d%c",now,i<n?' ':'\n');
	}return 0;
}
