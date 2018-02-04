#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 200,oo= 1e9;
bool vis[maxn][maxn];
int f[maxn][maxn],sum[maxn],a[maxn];
int A,n,i;
void init(){
	memset(vis,0,sizeof(vis));
}
int dp(int l,int r){
	if (l>r) return 0;
	if (vis[l][r]) return f[l][r];
	int i,m= oo;
	for (i= l;i<=r;i++){
		m= min(m,dp(i+1,r));
		m= min(m,dp(l,i-1));
	}
	vis[l][r]= 1;
	return f[l][r]= sum[r]-sum[l-1]-m;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		if (!n) break;
		init();
		for (i= 1;i<=n;i++){
			scanf("%d",&a[i]);
			sum[i]= sum[i-1]+a[i];
		}
		A= dp(1,n);
		printf("%d\n",2*A-sum[n]);
	}return 0;
}
