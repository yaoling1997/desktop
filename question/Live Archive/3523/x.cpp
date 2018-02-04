#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 1010,maxm= 2e6;
struct edge{
	int u,v;
}sta[maxm];
vector<int> g[maxn];
vector<int> b[maxn];
vector<int> bcc[maxn];
int a[maxn][maxn],pre[maxn],low[maxn];
int bccno[maxn],cut[maxn],d[maxn],ans[maxn];
int n,m,i,j,x,y,la,tim,cnt,tot;
void dfs(int o,int fa){
	low[o]= pre[o]= ++tim;
	int len= g[o].size(),i,child= 0;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		edge e= (edge){o,v};
		if (!pre[v]){
			child++;
			sta[++la]= e;
			dfs(v,o);
			low[o]= min(low[o],low[v]);			
			if (pre[o]<=low[v]){
				cut[o]= 1;
				cnt++;
				for (;;){
					edge x= sta[la--];
					if (bccno[x.u]!=cnt){
						bccno[x.u]= cnt;
						bcc[cnt].push_back(x.u);
					}
					if (bccno[x.v]!=cnt){
						bccno[x.v]= cnt;
						bcc[cnt].push_back(x.v);
					}
					if (x.u==o&&x.v==v) break;
				}
			}
		}else if (pre[v]<pre[o]&&v!=fa){
			low[o]= min(low[o],pre[v]);
			sta[++la]= e;
		}
	}
	if (child<=1&&fa==-1) cut[o]= 0;
}
bool ok(int o,int c){
	d[o]= c;
	int len= b[o].size(),i;
	for (i= 0;i<len;i++){
		int v= b[o][i];
		if (d[v]==d[o]) return 0;
		if (!d[v]) if (!ok(v,3-c)) return 0;
	}return 1;
}
void init(){
	memset(a,0,sizeof(a));
	memset(pre,0,sizeof(pre));
	memset(low,0,sizeof(low));
	memset(ans,0,sizeof(ans));
	memset(bccno,0,sizeof(bccno));
	tim= cnt= tot= 0;
	int i;
	for (i= 1;i<=n;i++){
		g[i].clear();
		bcc[i].clear();
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	while (scanf("%d%d",&n, &m)>0){
		if (!n) break;
		init();
		for (i= 1;i<=m;i++){
			scanf("%d%d",&x, &y);
			a[x][y]= a[y][x]= 1;
		}
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++){
				if (i==j||a[i][j]) continue;
				g[i].push_back(j);
			}
		for (i= 1;i<=n;i++)
			if (!pre[i])
				dfs(i,-1);
		for (i= 1;i<=cnt;i++){
			int L= bcc[i].size(),j;
			if (L<=2) continue;
			for (j= 0;j<L;j++){
				int u= bcc[i][j];
				b[u].clear();
				d[u]= 0;
				bccno[u]= i;
			}
			for (j= 0;j<L;j++){
				int u= bcc[i][j],len= g[u].size(),k;
				for (k= 0;k<len;k++){
					int v= g[u][k];
					if (bccno[v]==bccno[u]){
						b[u].push_back(v);
						b[v].push_back(u);
					}
				}
			}
			if (!ok(bcc[i][0],1)){
				for (j= 0;j<L;j++){
					int u= bcc[i][j];
					ans[u]= 1;
				}
			}
		}
		for (i= 1;i<=n;i++)
			if (!ans[i]){
				tot++;
			}
		printf("%d\n",tot);
	}return 0;
}
