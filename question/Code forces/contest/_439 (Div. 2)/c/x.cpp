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
const int mo= 998244353;
const int maxn= 6000,M= 5000;
int f[maxn][maxn];
int a,b,c,i,j;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&a,&b,&c);
	for (i= 0;i<=M;i++){
        f[i][0]=1;
        f[0][i]=1;
	}
	for (i= 1;i<=M;i++)
        for (j=1;j<=M;j++)
            f[i][j]= ((ll)j*f[i-1][j-1]+f[i-1][j])%mo;
    int ans= (ll)f[a][b]*f[b][c]%mo*f[c][a]%mo;
    printf("%d",ans);
    return 0;
}
