#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn= 3001;
vector<int> edges;
vector<int> g[maxn];
int f[maxn],a[maxn][2];
int n,m,i,j,ans,x,y;
void addedge(int x,int y){
	edges.push_back(y);
	g[x].push_back(edges.size()-1);
}
int dfs(int o){
	if (f[o]) return f[o];
	f[o]= 1;int len= g[o].size(),i;
	for (i= 0;i<len;i++)
		f[o]= max(f[o],dfs(edges[g[o][i]])+1);
	return f[o];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d %d",&x, &y);
		if (x>y) swap(x,y);
		a[i][0]= x;a[i][1]= y;
		for (j= 1;j<i;j++){
			int x1= a[j][0],y1= a[j][1];
			if (x1<x && y1<y)
				addedge(j,i);
		}
	}
	for (i= 1;i<=n;i++){
		dfs(i);
		ans= max(ans,f[i]);
	}
	printf("%d",ans);
	return 0;
}
