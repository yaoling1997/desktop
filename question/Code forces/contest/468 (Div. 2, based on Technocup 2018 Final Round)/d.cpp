#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int h[maxn],des[maxn],nex[maxn];
int d[maxn];
int n,tot;
void addedge(int u,int v){
	nex[++tot]=h[u];
	des[tot]=v;
	h[u]=tot;
}
void dfs(int o,int fa,int c){
	d[c]^=1;
	for (int i=h[o];i;i=nex[i]){
		int v=des[i];
		if (v==fa)
			continue;
		dfs(v,o,c+1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		addedge(x,i);
	}
	dfs(1,0,1);
	int ans=0;
	for (int i=1;i<=n;i++)
		ans+= d[i];
	printf("%d",ans);
}
