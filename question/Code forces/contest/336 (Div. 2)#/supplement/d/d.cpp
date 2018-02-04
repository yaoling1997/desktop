#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 600,oo= 1e9;
int a[maxn],f[maxn][maxn];
int n,i;
int dfs(int l,int r){
	int &re= f[l][r];
	if (re!=-1) return re;
	if (l>=r) return re= 1;
	if (a[l]==a[r]) re= dfs(l+1,r-1);
	else re= oo;
	for (int i= l;i<r;i++)
		re= min(re,dfs(l,i)+dfs(i+1,r));
	return re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,-1,sizeof(f));
	dfs(1,n);
	printf("%d\n",f[1][n]);
	return 0;
}
