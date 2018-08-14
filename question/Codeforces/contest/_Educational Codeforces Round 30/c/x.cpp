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
int a[300][300];
int n,m,k,i,j,ans,repAns;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &m, &k);
	for (int i= 1;i<=n;i++)
		for (int j= 1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int j= 1;j<=m;j++){
		int sum= 0,Max= 0,rep= 0,repB= 0;
		for (int i= 1;i<=k;i++)
			if (a[i][j]==1)
				sum++;
		for (int i= 1;i<=n;i++){
			if (a[i][j]==1){
				if (sum>Max){
					Max= sum;
					repB= rep;
				}
				rep++;
			}
			sum= sum-a[i][j]+a[i+k][j];
		}
		ans+= Max;
		repAns+= repB;
	}
	printf("%d %d",ans,repAns);
	return 0;
}
