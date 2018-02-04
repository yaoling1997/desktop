#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 5e5,oo= 1e9;
vector<int> g[maxn];
int X[maxn],Y[maxn],b[maxn],sta[maxn];
double av;
int n,m,i,j,x,y,la,tim;
bool sameLevel(int x,int y){
	return (Y[x]<av&&Y[y]<av)||(Y[x]>=av&&Y[y]>=av);
}
void addedge(int x,int y){
	g[x].push_back(y);
}
void init(){
	int i;
	av= 0;tim++;
	for (i= 1;i<=n;i++){
		g[i].clear();
		g[i+n].clear();
		X[i]= i+n;
		X[i+n]= i;
	}
}
bool dfs(int o){
	if (b[X[o]]==tim) return 0;
	if (b[o]==tim) return 1;
	b[o]= tim;
	sta[++la]= o;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!dfs(v)) return 0;
	}return 1;
}
bool solve(){
	for (int i= 1;i<=n;i++){
		if (b[i]==tim||b[X[i]]==tim) continue;
		la= 0;
		if (!dfs(i)){
			while (la) b[sta[la--]]= 0;
			if (!dfs(X[i])) return 0;
		}
	}return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d%d",&n, &m)>0){
		if (!n) break;
		init();
		for (i= 1;i<=n;i++){
			scanf("%d",&Y[i]);
			av+= Y[i];
		}
		av/= n;
		for (i= 1;i<=m;i++){
			scanf("%d%d",&x, &y);
			if (x==y) continue;
			if (sameLevel(x,y)){
				addedge(x,X[y]);
				addedge(y,X[x]);
				addedge(X[x],y);
				addedge(X[y],x);
			}else {
				addedge(x,X[y]);
				addedge(y,X[x]);
			}
		}
		if (!solve()) printf("No solution.\n");
		else 
			for (i= 1;i<=n;i++)
				printf("%c\n",b[i]==tim?'C':(Y[i]<av?'B':'A'));		
	}return 0;
}
