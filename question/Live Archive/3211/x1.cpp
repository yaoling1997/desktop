#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 5001;
vector<int> g[maxn];
int early[maxn],late[maxn],X[maxn],b[maxn],sta[maxn];
int n,M,i,la;
void addedge(int x,int y){
	g[x].push_back(y);
}
bool dfs(int o){
	if (b[X[o]]) return 0;
	if (b[o]) return 1;
	b[o]= 1;
	sta[++la]= o;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!dfs(v)) return 0;
	}return 1;
}
bool solve(){
	int i;
	for (i= 1;i<=n;i++){
		if (b[i]||b[X[i]]) continue;
		la= 0;
		if (!dfs(i)){
			while (la) b[sta[la--]]= 0;
			if (!dfs(X[i])) return 0;
		}
	}return 1;
}
bool ok(int gap){
	int i,j;
	memset(b,0,sizeof(b));
	for (i= 1;i<=n;i++){
		g[i].clear();
		g[i+n].clear();
	}
	for (i= 1;i<=n;i++)
		for (j= i+1;j<=n;j++){
			if (abs(early[i]-early[j])<gap){
				addedge(i,X[j]);
				addedge(j,X[i]);
			}
			if (abs(early[i]-late[j])<gap){
				addedge(i,j);
				addedge(X[j],X[i]);
			}
			if (abs(late[i]-early[j])<gap){
				addedge(X[i],X[j]);
				addedge(j,i);
			}
			if (abs(late[i]-late[j])<gap){
				addedge(X[i],j);
				addedge(X[j],i);
			}
		}
	return solve();
}
void init(){
	memset(b,0,sizeof(b));
	M= 0;
	for (int i= 1;i<=n;i++){
		g[i].clear();
		g[i+n].clear();
		X[i]= i+n;
		X[i+n]= i;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		init();
		for (i= 1;i<=n;i++){
			scanf("%d%d",&early[i], &late[i]);
			if (early[i]>late[i])
				swap(early[i],late[i]);
			M= max(M,late[i]);
		}
		int l= 0,r= M+1;
		while (l+1<r){
			int mid= (l+r)>>1;
			if (ok(mid)) l= mid;
			else r= mid;
		}
		printf("%d\n",l);
	}return 0;
}
