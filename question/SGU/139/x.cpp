#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 10;
int a[maxn][maxn];
int b[maxn*maxn];
int i,j,k,z,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	for (i= 1;i<=4;i++)
		for (j= 1;j<=4;j++){
			scanf("%d",&a[i][j]);
			b[++k]= a[i][j];
			for (z= 1;z<k;z++)
				ans+= b[z]>b[k];
			if (!a[i][j])
				ans+= 4-i+4-j;
		}
	ans&= 1;
	if (ans) printf("YES");
	else printf("NO");
	return 0;
}
