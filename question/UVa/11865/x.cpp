#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 101,oo= 1e9+2;
struct edge{
	ll from,to,b,c;
};
edge q[20000];
ll w[maxn][maxn],vis[maxn];
ll removed[maxn],pre[maxn],iw[maxn],cid[maxn];
ll n,m,cost,T,i,max_cid,ans,l,r;
bool cmp(edge a,edge b){
	return a.b>b.b;
}
void init(){
	int i,j;
	for (i= 0;i<n;i++)
		for (j= 0;j<n;j++)
			w[i][j]= oo;
	memset(vis,0,sizeof(vis));
	memset(removed,0,sizeof(removed));
	memset(cid,0,sizeof(cid));
}
void addedge(int x,int y,ll z){
	if (x!=y)
		w[x][y]= min(w[x][y],z);
}
int dfs(int o){
	vis[o]= 1;int re= 1;
	for (int i= 0;i<n;i++)
		if (!vis[i]&&w[o][i]!=oo)
			re+= dfs(i);
	return re;
}
bool cycle(int u){
	max_cid++;
	int v= u;
	while (cid[v]!=max_cid){cid[v]= max_cid;v= pre[v];}
	return u==v;
}
void update(int u){
	iw[u]= oo;
	for (int i= 0;i<n;i++)
		if (!removed[i]&&iw[u]>w[i][u])
			iw[u]= w[i][u],pre[u]= i;
}
bool get(int mid,int s){
	init();
	int i,u;
	for (i= 1;i<=mid;i++)
		addedge(q[i].from,q[i].to,q[i].c);
	if (dfs(s)!=n) return 0;
	for (i= 0;i<n;i++)
		update(i);
	iw[s]= 0;pre[s]= s;
	ans= max_cid= 0;
	for (;;){
		int bl= 0;
		for (u= 0;u<n;u++)
			if (u!=s&&!removed[u]&&cycle(u)){
				bl= 1;int v= u;
				do {
					if (v!=u) removed[v]= 1;
					ans+= iw[v];
					for (i= 0;i<n;i++)
						if (!removed[i]&&cid[i]!=cid[u]){
							if (w[i][v]!=oo)
								w[i][u]= min(w[i][u],w[i][v]-iw[v]);	  						 w[u][i]= min(w[u][i],w[v][i]);
							if (pre[i]==v)
								pre[i]= u;
						}
					v= pre[v];
				}while (v!=u);
				update(u);
				break;				
			}		
		if (!bl) break;
	}
	for (i= 0;i<n;i++)
		if (!removed[i])
			ans+= iw[i];
	return ans<=cost;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%lld",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%lld %lld %lld",&n, &m, &cost);
		for (i= 1;i<=m;i++)
			scanf("%lld %lld %lld %lld",&q[i].from,&q[i].to,&q[i].b,&q[i].c);
		sort(q+1,q+m+1,cmp);
		if (!get(m,0)){
			printf("streaming not possible.\n");
			continue;
		}
		l= 0;r= m+1;
		while (l+1<r){
			int mid= (l+r)>>1;
			init();
			if (get(mid,0)){
				r= mid;
			}else {
				l= mid;
			}
		}
		printf("%lld kbps\n",q[r].b);
	}
	return 0;
}
