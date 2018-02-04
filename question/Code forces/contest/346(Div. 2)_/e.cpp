#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int d[maxn],vis[maxn],f[maxn];
int N[maxn],M[maxn];
int n,m,i,j,x,y,ans;
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++)
		f[i]= i;
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		find(x);
		find(y);
		f[f[x]]= f[y];
		d[x]++;
	}
	for (i= 1;i<=n;i++){
		find(i);
		N[f[i]]++;
		M[f[i]]+= d[i];
	}
	for (i= 1;i<=n;i++)
		if (N[i]>M[i])
			ans++;
	printf("%d\n",ans);
	return 0;
}