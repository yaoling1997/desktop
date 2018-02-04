#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn= 3001,oo= 1e8;
vector<int> g[maxn];
int f[maxn];
int n,i,x,y,ans,s;
void dfs(int o,int fa){
	f[o]= 1;int len= g[o].size(),i,sz= 0;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa) continue;		
		dfs(v,o);
		sz= max(sz,f[v]);
		f[o]+= f[v];
	}
	sz= max(sz,n-f[o]);
	if (sz<s){
		s= sz;
		ans= o;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<n;i++){
		scanf("%d %d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	s= oo;
	dfs(1,-1);
	printf("%d",ans);
	return 0;
}
