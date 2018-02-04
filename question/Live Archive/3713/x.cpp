#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 400001,base= 200000;
vector<int> g[maxn];
int b[maxn],c[maxn],stack[maxn],X[maxn];
int n,m,i,x,y,la,bl,time;
double d;
void init(int n){
	int i;la= d= 0;time++;
	for (i= 1;i<=n;i++){
		g[i].clear(),g[i+base].clear();
		X[i]= i+base;X[i+base]= i;
	}
}
bool dfs(int o){
	if (b[X[o]]==time) return 0;
	if (b[o]==time) return 1;
	b[o]= time;stack[++la]= o;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!dfs(v)) return 0;
	}
	return 1;
}
bool solve(int n){
	int i;
	for (i= 1;i<=n;i++)
		if (b[i]!=time && b[X[i]]!=time){
			la= 0;
			if (!dfs(i)){
				while (la) b[stack[la--]]= 0;
				if (!dfs(X[i])) return 0;
			}
		}
	return 1;
}
void print(int n){
	int i;
	for (i= 1;i<=n;i++)
		if (c[i]==1){
			if (b[i+base]==time) printf("A\n");
			else printf("C\n");
		}else {
			if (b[i+base]==time) printf("B\n");
			else printf("C\n");
		}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (true){
		scanf("%d %d",&n, &m);
		init(n);
		if (!n && !m) return 0;
		for (i= 1;i<=n;i++){
			scanf("%d",&c[i]);
			d+= c[i];
		}
		d/= n;
		for (i= 1;i<=n;i++)
			if (c[i]>=d) c[i]= 1;
			else c[i]= 2;
		for (i= 1;i<=m;i++){
			scanf("%d %d",&x, &y);
			if (x==y) continue;
			g[x].push_back(y+base);
			g[y].push_back(x+base);
			if (c[x]==c[y]){
				g[x+base].push_back(y);
				g[y+base].push_back(x);
			}
		}
		bl= solve(n);
		if (bl) print(n);
		else printf("No solution.\n");
	}
	return 0;
}
