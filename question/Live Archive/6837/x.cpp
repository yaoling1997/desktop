#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 5e5;
struct edge{
	int u,v,w;
	bool operator <(const edge a)const{
		return w<a.w;
	}
};
struct EDGE{
	int to,h;
};
vector<EDGE> g[maxn];
edge E[maxn];
int b[maxn],low[maxn],pre[maxn],f[maxn];
int x,y,z,n,m,i,j,k,cnt,ans,tim,top;
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
void init(){
	memset(E,0,sizeof(E));
	memset(b,0,sizeof(b));
	cnt= ans= 0;
	for (int i= 1;i<=n;i++) f[i]= i;
}
void dfs(int o,int fa){
	low[o]= pre[o]= ++tim;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		EDGE &e= g[o][i];
		int v= e.to;
		if (!pre[v]){
			dfs(v,e.h);
			low[o]= min(low[o],low[v]);
			if (low[v]>pre[o]) b[e.h]= 1;
		}else if (pre[v]<pre[o] && e.h!=fa)
			low[o]= min(low[o],pre[v]);
	}
}
int main()
{
	while (scanf("%d%d",&n, &m)>0){
		init();
		for (i= 1;i<=m;i++){
			scanf("%d%d%d",&x, &y, &z);
			E[i]= (edge){x,y,z};
		}
		sort(E+1,E+m+1);
		i= 1;
		while (i<=m){
			j= i+1;
			while (E[j].w==E[i].w&&j<=m) j++;
			if (j-i==1){
				x= E[i].u;
				y= E[i].v;
				find(x);find(y);
				if (f[x]!=f[y]){
					f[f[x]]= f[y];
					cnt++;
					ans+= E[i].w;
				}
			}else {
				for (k= i;k<j;k++){
					x= E[k].u;
					y= E[k].v;
					find(x);find(y);
					g[f[x]].clear();
					g[f[y]].clear();
					pre[f[x]]= pre[f[y]]= 0;
					low[f[x]]= low[f[y]]= 0;
				}
				for (k= i;k<j;k++){
					x= E[k].u;
					y= E[k].v;
					find(x);find(y);
					if (f[x]!=f[y]){
						g[f[x]].push_back((EDGE){f[y],k});
						g[f[y]].push_back((EDGE){f[x],k});
					}
				}
				for (k= i;k<j;k++){
					x= E[k].u;
					y= E[k].v;
					find(x);find(y);
					if (f[x]==f[y]) continue;
					if (!pre[f[x]])
						dfs(f[x],-1);
				}				
				for (k= i;k<j;k++){
					x= E[k].u;
					y= E[k].v;
					find(x);find(y);
					if (f[x]==f[y]) continue;
					if (b[k]){
						cnt++;
						ans+= E[k].w;
					}
				}				
				for (k= i;k<j;k++){
					x= E[k].u;
					y= E[k].v;
					find(x);find(y);
					f[f[x]]= f[y];
				}				
			}
			i= j;			
		}
		printf("%d %d\n",cnt, ans);
	}return 0;
}

