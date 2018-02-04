#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn= 3001,maxm= 1000,oo= 1e7;
struct edge{
	int u,w;
};
struct tim{
	int t1,t2;
};
vector<edge> g[maxn];
vector<tim> tt[maxn];
int f[maxn],b[maxn],vis[maxn],d[maxn],l[3*maxm];
int n,m,K,P,i,j,x,y,z,len,t;
void addedge(int o,int u,int w){
	int i,len= g[o].size();
	for (i= 0;i<len;i++)
		if (g[o][i].u==u) break;
	if (i==len) g[o].push_back((edge){u,w});
	else g[o][i].w= min(g[o][i].w,w);
}
int count(int o1,int o2){
	int re= 0,i,j,len,t1,t2,F= 0,R= 1;
	memset(b,0,sizeof(b));memset(vis,0,sizeof(vis));
	for (i= 1;i<=n;i++) d[i]= oo;
	for (i= 1;i<=n;i++){
		len= tt[i].size();
		for (j= 0;j<len;j++){
			t1= tt[i][j].t1;t2= tt[i][j].t2;
			if (!(t1>o1 || t2<=o2)) break;
		}
		if (j!=len) b[i]= 1;
	}
	l[R]= 1;d[1]= 0;
	while (F<R){
		int u= l[++F];
		vis[u]= 0; len= g[u].size();
		for (i= 0;i<len;i++){
			edge e= g[u][i];
			if (!b[e.u] && d[e.u]>d[u]+e.w){
				d[e.u]= d[u]+e.w;
				if (!vis[e.u]){
					vis[e.u]= 1;
					l[++R]= e.u;
				}
			}
		}
	}
	re= d[n]*(o1-o2)+K+f[o2];
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d %d",&t, &n, &K, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		addedge(x,y,z);
		addedge(y,x,z);
	}
	scanf("%d",&P);
	for (i= 1;i<=P;i++){
		scanf("%d %d %d",&x, &y, &z);
		if (y>z) swap(y,z);
		tt[x].push_back((tim){y,z});
	}
	for (i= 1;i<=t;i++){
		f[i]= oo;
		for (j= 0;j<i;j++){
			x= count(i,j);
			f[i]= min(f[i],x);
		}
	}
	printf("%d",f[t]-K);
	return 0;
}
