#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 3001,oo= 99999999+1;
int c[maxn][maxn];
int a,b,n,amax,amin,ans= oo,i,j,k,z;
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d %d %d\n",&a, &b, &n);
	for (i= 1;i<=a;i++)
		for (j= 1;j<=b;j++)
			scanf("%d",&c[i][j]);
	for (i= 1;i<=a-n+1;i++)
		for (j= 1;j<=b-n+1;j++){
			amax= -oo;amin= oo;
			for (k= i;k<=i+n-1;k++)
				for (z= j;z<=j+n-1;z++){
					amax= max(amax,c[k][z]);
					amin= min(amin,c[k][z]);
				}
			ans= min(ans,amax-amin);
		}
	printf("%d",ans);
}
