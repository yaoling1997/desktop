#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 3001,oo= 1e9;
struct edge{
	int v,w;
};
vector<edge> g[maxn];
queue<int> Q;
int vis[maxn],d[maxn];
int s,i,n,m,x,y,z;
void spfa(){
	int i;
	for (i= 1;i<=n;i++) d[i]= oo;
	d[s]= 0;
	Q.push(s);
	vis[s]= 1;
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size();
		Q.pop();
		vis[u]= 0;
		for (i= 0;i<len;i++){
			edge &e= g[u][i];
			if (d[e.v]>d[u]+e.w){
				d[e.v]= d[u]+e.w;
				if (!vis[e.v]){
					vis[e.v]= 1;
					Q.push(e.v);
				}
			}
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &m, &s);
	for (i= 1;i<=m;i++){
		scanf("%d%d%d",&x, &y, &z);
		g[x].push_back((edge){y,z});
	}
	spfa();
	for (i= 1;i<=n;i++)
		printf("%d%c",d[i], i<n?' ':'\n');
	return 0;
}
