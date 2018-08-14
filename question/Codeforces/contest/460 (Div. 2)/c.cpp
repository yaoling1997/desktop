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
const int maxn= 3000;
char s[maxn][maxn];
int h[maxn][maxn],v[maxn][maxn];
int n,m,K,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &m, &K);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int i= 1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='.'){
				h[i][j]=h[i][j-1]+1;
				v[i][j]=v[i-1][j]+1;
				if (h[i][j]>=K)
					ans++;
				if (v[i][j]>=K&&K>1)
					ans++;				
			}
	printf("%d",ans);
	return 0;
}
