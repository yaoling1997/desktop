#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const int maxn= 400001,k= 15;
int des[maxn],next[maxn],head[maxn],f[maxn][20],d[maxn];
int tot,x,y,i,j,n,m,now;
ll ans;
void addedge(int x,int y){
	next[++tot]= head[x];
	des[tot]= y;
	head[x]= tot;
}
void dfs(int o,int dep){
	int p= head[o];
	d[o]= dep;
	while (p){
		if (des[p]!=f[o][0]){
			f[des[p]][0]= o;
			dfs(des[p],dep+1);
		}
		p= next[p];
	}
}
void LCA(int x,int y){
	int i,once= 0;
	if (d[x]<d[y]) swap(x,y);
	for (i= k;i>=0;i--)
		if (d[f[x][i]]>=d[y]){
			once+= 1<<i;
			x= f[x][i];
		}
	if (x!=y){
		for (i= k;i>=0;i--)
			if (f[x][i]!=f[y][i])
				once+= 1<<(i+1),x= f[x][i],y= f[y][i];
		once+= 2;
	}
	ans= ans+once;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<n;i++){
		scanf("%d %d",&x, &y);
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,1);
	for (i= 1;i<=k;i++)
		for (j= 1;j<=n;j++)
			f[j][i]= f[f[j][i-1]][i-1];
	scanf("%d",&m);
	now= 1;
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		LCA(now,x);
		now= x;
	}
	printf("%lld",ans);
	return 0;
}
