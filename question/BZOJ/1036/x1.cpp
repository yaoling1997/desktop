#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;
const int maxn= 3001,oo= 99999999;
vector<int> g[maxn];
char ch;
int c[maxn],vis[maxn];
int x,y,i,j,n,askmax,asksum,bl,q;
void dfs(int o,int s){
	if (o==y){
		asksum= s+c[y];
		bl= 1;
		askmax= max(askmax,c[o]);
		return;
	}
	vis[o]= 1;s+= c[o];
	int len= g[o].size();
	for (int i= 0;i<len;i++){
		int v= g[o][i];
		if (!vis[v])
			dfs(v,s);
		if (bl){
			askmax= max(askmax,c[o]);
			return;
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n-1;i++){
		scanf("%d %d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (i= 1;i<=n;i++)
		scanf("%d",&c[i]);
	scanf("%d",&q);
	for (i= 1;i<=q;i++){
		bl= 0;memset(vis,0,sizeof(vis));
		for (j= 1;j<=5;j++)
			scanf("%c",&ch);
		askmax= -oo;asksum= 0;
		if (ch=='X'){
			scanf("%d %d",&x, &y);
			dfs(x,0);
			printf("%d\n",askmax);
		}else if (ch=='M'){
			scanf("%d %d",&x, &y);
			dfs(x,0);
			printf("%d\n",asksum);
		}else {
			for (j= 1;j<=2;j++)
				scanf("%c",&ch);
			scanf("%d %d",&x, &y);
			c[x]= y;
		}
	}
	return 0;
}
