#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 310,maxk= 22,mo= 12345678;
int f[maxn][160][maxk][maxk];
int n,m,i,j,k,z,K,x,ans;
void update(int &a,int b){
	a+= b;
	a-= a/mo*mo;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &m, &K);
	f[0][0][0][0]= 1;
	for (i= 0;i<=n+m;i++)
		for (j= 0;j<=n;j++)
			for (k= 0;k<=K;k++)
				for (z= 0;z<=K;z++){
					x= f[i][j][k][z];
					if (x){
						update(f[i+1][j+1][k+1][max(z-1,0)],x);
						update(f[i+1][j][max(k-1,0)][z+1],x);
					}
				}
	for (i= 0;i<=K;i++)
		for (j= 0;j<=K;j++)
			update(ans,f[n+m][n][i][j]);
	printf("%d\n",ans);
	return 0;
}
