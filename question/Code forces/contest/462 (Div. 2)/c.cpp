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
int f[maxn][5];
int a[maxn],b[5]={0,1,2,1,2};
int n,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for (int j=1;j<5;j++){
			f[i][j]=max(f[i][j],f[i-1][j]);
			if (x==b[j])
				f[i][j]=max(f[i-1][j]+1,f[i][j]);
			else if (j<4){
				f[i][j+1]=max(f[i][j+1],f[i-1][j]+1);
			}
			ans= max(ans,f[i][j]);
		}
	}
	printf("%d",ans);
	return 0;
}
