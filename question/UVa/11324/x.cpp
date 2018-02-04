#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001;
vector<int> g[maxn],G[maxn];
int pre[maxn],low[maxn],sccno[maxn],f[maxn],stack[maxn],scc[maxn];
int n,m,a1,i,x,y,z,T,time,ans,cnt,la;
void init(int n){
	cnt= ans= 0;
	memset(sccno,0,sizeof(sccno));
	memset(pre,0,sizeof(pre));
	memset(low,0,sizeof(low));
	memset(scc,0,sizeof(scc));
	memset(f,-1,sizeof(f));
	int i;
	for (i= 1;i<=n;i++)
		g[i].clear(),G[i].clear();
}
void Dfs(int o){
	low[o]= pre[o]= ++time;
	stack[++la]= o;int i,len= g[o].size();
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!pre[v]){
			Dfs(v);
			low[o]= min(low[o],low[v]);
		}else if (!sccno[v])
			low[o]= min(low[o],pre[v]);
	}
	if (low[o]==pre[o]){
		cnt++;
		while (true){
			int x= stack[la--];
			sccno[x]= cnt;
			scc[cnt]++;
			if (x==o) break;
		}
	}
}
void get(){
	int i,j;
	for (i= 1;i<=n;i++){
		int len= g[i].size();
		for (j= 0;j<len;j++){
			int v= g[i][j];
			if (sccno[i]!=sccno[v])
				G[sccno[i]].push_back(sccno[v]);
		}
	}
}
int dfs(int o){
	if (f[o]!=-1) return f[o];
	f[o]= scc[o];int i,len= G[o].size();
	for (i= 0;i<len;i++){
		int v= G[o][i];
		f[o]= max(f[o],dfs(v)+scc[o]);
	}
	return f[o];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d %d",&n, &m);
		init(n);
		for (i= 1;i<=m;i++){
			scanf("%d %d",&x, &y);
			g[x].push_back(y);
		}
		for (i= 1;i<=n;i++)
			if (!pre[i])
				Dfs(i);
		get();
		for (i= 1;i<=cnt;i++)
			ans= max(ans,dfs(i));		
		printf("%d\n",ans);
	}
	return 0;
}
