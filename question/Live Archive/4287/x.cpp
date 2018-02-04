#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e4;
int sccno[maxn],pre[maxn],low[maxn],sta[maxn];
int rd[maxn],cd[maxn];
vector<int> g[maxn],scc[maxn];
int T,i,j,n,m,x,y,tim,la,cnt,ans;
void init(){
	int i;
	memset(sccno,0,sizeof(sccno));
	memset(pre,0,sizeof(pre));
	memset(low,0,sizeof(low));
	memset(rd,0,sizeof(rd));
	memset(cd,0,sizeof(cd));
	tim= cnt= 0;
	for (i= 1;i<=n;i++){
		g[i].clear();
		scc[i].clear();
	}
}
void dfs(int o){
	low[o]= pre[o]= ++tim;
	sta[++la]= o;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!pre[v]){
			dfs(v);
			low[o]= min(low[o],low[v]);
		}else if (!sccno[v])
			low[o]= min(low[o],pre[v]);
	}
	if (pre[o]==low[o]){
		cnt++;
		for (;;){
			int x= sta[la--];
			sccno[x]= cnt;
			scc[cnt].push_back(x);
			if (x==o) break;
		}
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n, &m);
		init();
		for (i= 1;i<=m;i++){
			scanf("%d%d",&x, &y);
			g[x].push_back(y);
		}
		for (i= 1;i<=n;i++)
			if (!pre[i])
				dfs(i);
		if (cnt==1){
			printf("0\n");
			continue;
		}
		for (i= 1;i<=n;i++){
			int len= g[i].size();
			for (j= 0;j<len;j++){
				int v= g[i][j];
				if (sccno[i]==sccno[v]) continue;
				cd[sccno[i]]++;
				rd[sccno[v]]++;
			}
		}
		x= y= 0;
		for (i= 1;i<=cnt;i++)
			x+= !rd[i],y+= !cd[i];
		ans= max(x,y);
		printf("%d\n",ans);
	}return 0;
}
