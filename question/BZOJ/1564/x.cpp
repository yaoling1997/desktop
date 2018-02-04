#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define ll int
const ll oo= 2e9;
const int maxn= 80;
struct node{
	int d,v,p;
};
node a[maxn];
ll f[maxn][maxn][maxn];
int sum[maxn];
ll ans;
int n,K,i,j,k;
bool cmp(node a,node b){return a.v<b.v;}
bool cmp1(node a,node b){return a.d<b.d;}
void disperse(){
	sort(a+1,a+n+1,cmp);
	int tot= 1,v= a[1].v,i;
	for (i= 1;i<=n;i++)
		if (a[i].v==v) a[i].v= tot;
		else v= a[i].v,a[i].v= ++tot;
}
void dfs(int i,int j,int b){
	ll &res= f[i][j][b];
	if (res!=-1) return;
	ll k;res= oo;
	for (k= i;k<=j;k++){
		dfs(i,k-1,b);dfs(k+1,j,b);
		res= min(res,f[i][k-1][b]+f[k+1][j][b]+K+sum[j]-sum[i-1]);
		int x= a[k].v;
		if (x>=b){
			dfs(i,k-1,x);dfs(k+1,j,x);
			res= min(res,f[i][k-1][x]+f[k+1][j][x]+sum[j]-sum[i-1]);
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &K);
	for (i= 1;i<=n;i++)	scanf("%d",&a[i].d);
	for (i= 1;i<=n;i++)	scanf("%d",&a[i].v);
	for (i= 1;i<=n;i++)	scanf("%d",&a[i].p);
	disperse();
	sort(a+1,a+n+1,cmp1);
	for (i= 1;i<=n;i++) sum[i]= sum[i-1]+a[i].p;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			for (k= 1;k<=n;k++)
				f[i][j][k]= -1;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			f[i][i][j]= a[i].v>=j?a[i].p:a[i].p+K,f[i][i-1][j]= f[i+1][i][j]= 0;
	ans= oo;
	for (i= 1;i<=n;i++){
		dfs(1,n,i);
		ans= min(ans,f[1][n][i]);
	}printf("%d",ans);
	return 0;
}