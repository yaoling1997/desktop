#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 3001,base= 1000,oo= 1e8;
vector<int> g[maxn];
int b[maxn],X[maxn],stack[maxn];
int n,m,i,j,x,x1,y1,x2,y2,la;
void addedge(int x,int y){
	g[x].push_back(y);
}
void link(int x1,int y1,int x2,int y2){
	if (y1){
		if (y2){
			addedge(x1+base,x2);
			addedge(x2+base,x1);
		}else {
			addedge(x1+base,x2+base);
			addedge(x2,x1);			
		}
	}else {
		if (y2){
			addedge(x1,x2);
			addedge(x2+base,x1+base);			
		}else {
			addedge(x1,x2+base);
			addedge(x2,x1+base);			
		}
	}
}
bool dfs(int o){
	if (b[X[o]]) return 0;
	if (b[o]) return 1;
	b[o]= 1;stack[++la]= o;
	int i,len= g[o].size();
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!dfs(v))
			return 0;
	}
	return 1;
}
bool solve(int n){
	for (i= 1;i<=n;i++)
		if (!b[i]&&!b[X[i]]){
			la= 0;
			if (!dfs(i)){
				while (la) b[stack[la--]]= 0;
				if (!dfs(X[i])) return 0;
			}
		}
	return 1;
}
void init(int n){
	for (i= 1;i<=n;i++)
		g[i].clear(),g[i+base].clear(),X[i]= i+base,X[i+base]= i;
	memset(b,0,sizeof(b));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	init(n);
	for (i= 1;i<=m;i++){
		scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
		link(x1,y1,x2,y2);
	}
	if (solve(n)) printf("yes!");
	else printf("no!");
	return 0;
}
