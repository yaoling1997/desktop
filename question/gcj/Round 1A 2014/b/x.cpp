#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e3,oo= 1e9;
vector<int> g[maxn];
int f[maxn],size[maxn];
int T,n,i,j,x,y,ans;
void init(){	
	int i;ans= oo;
	for (i= 1;i<=n;i++){
		g[i].clear();
		size[i]= 0;
		f[i]= -1;
	}
}
void dfs(int o,int fa){
	size[o]= 1;
	f[o]= 0;
	int len= g[o].size(),i;
	vector<int> V;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa) continue;
		dfs(v,o);
		size[o]+= size[v];
		V.push_back(f[v]-size[v]);
	}
	int lv= V.size();
	f[o]= size[o]-1;
	if (lv<=1);
	else {
		sort(V.begin(),V.end());
		f[o]+= V[0]+V[1];
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		scanf("%d",&n);
		init();
		for (i= 1;i<n;i++){
			scanf("%d%d",&x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for (i= 1;i<=n;i++){
			dfs(i,0);
			ans= min(ans,f[i]);
		}
		printf("Case #%d: %d\n",t, ans);		
	}return 0;
}
