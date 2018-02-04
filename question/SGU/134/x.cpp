#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e4,oo= 1e9;
vector<int> g[maxn];
int f[maxn],sta[maxn],size[maxn];
int n,i,j,x,y,la,ans;
void dfs(int o,int fa){
	size[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa) continue;
		dfs(v,o);
		f[o]= max(f[o],size[v]);
		size[o]+= size[v];
	}
	f[o]= max(f[o],n-size[o]);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<n;i++){
		scanf("%d%d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	ans= oo;
	for (i= 1;i<=n;i++)
		if (f[i]<ans){
			ans= f[i];
			sta[la= 1]= i;
		}else if (f[i]==ans)
			sta[++la]= i;
	printf("%d %d\n",ans, la);
	for (i= 1;i<=la;i++)
		printf("%d%c",sta[i], i<la?' ':'\n');
	return 0;
}
