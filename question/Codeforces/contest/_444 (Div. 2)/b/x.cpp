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
int vis[10000];
int a[10][10];
int per[10];
int n,ans= 0;
void dfs(int o,int x){
	if (o>n){
		vis[x]= 1;
		return;
	}
	for (int i= 1;i<=6;i++)
		dfs(o+1,x*10+a[per[o]][i]);
	dfs(o+1,x);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i= 1;i<=n;i++)
		per[i]= i;
	for (int i= 1;i<=n;i++)
		for (int j= 1;j<=6;j++)
			scanf("%d",&a[i][j]);
	do{
		dfs(1,0);
	}while (next_permutation(per+1,per+n+1));
	for (int i= 1;i<=1000;i++){
		if (vis[i]==0) break;
		ans= i;
	}
	printf("%d",ans);
	return 0;
}
