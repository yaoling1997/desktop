#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 100,maxm= 2e3;
struct edge{
	int u,v,h;
}sta[maxm];
vector<edge> g[maxn];
int f[maxn],b[maxm];
int T,i,j,x,y,m,bl,cnt,la;
void init(){
	int i;
	memset(b,0,sizeof(b));
	for (i= 1;i<=50;i++){
		g[i].clear();
		f[i]= i;
	}
	la= 0;
	bl= 1;
}
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
void dfs(int o){
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		if (b[g[o][i].h]) continue;
		b[g[o][i].h]= 1;
		dfs(g[o][i].v);
		sta[++la]= g[o][i];
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		if (t!=1) printf("\n");
		printf("Case #%d\n",t);
		scanf("%d",&m);
		init();
		for (i= 1;i<=m;i++){
			scanf("%d%d",&x, &y);
			g[x].push_back((edge){x,y,i});
			g[y].push_back((edge){y,x,i});
			find(x);
			find(y);
			f[f[x]]= f[y];
		}
		for (i= 1;i<=50;i++)
			if (g[i].size()&1){
				bl= 0;
				break;
			}
		x= 0;
		for (i= 1;i<=50;i++){
			if (!g[i].size()) continue;
			find(i);
			if (!x) x= f[i];
			else if (x!=f[i]){
				bl= 0;
				break;
			}
		}
		if (bl){
			dfs(x);
			for (i= 1;i<=la;i++)
				printf("%d %d\n",sta[i].v, sta[i].u);
			//printf("ok\n");
		}else {
			printf("some beads may be lost\n");
		}
	}return 0;
}
