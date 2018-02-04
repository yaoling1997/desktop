#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 110,maxm= 1010,maxs= 1e5+10;
double f[maxn][maxs],sum[maxn][maxs];
int a[maxn];
int n,m,i,j,x,y,z,ms,k;
double s(int o,int j){
	if (j<0) return 0;
	return sum[o][j];
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	ms= n*m;
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		k+= a[i];
	}
	if (m==1){
		printf("1.0000000000000000000000");
		return 0;
	}
	f[0][0]= m-1;
	for (i= 0;i<=ms;i++)
		sum[0][i]= f[0][0];
	for (i= 1;i<=n;i++)
		for (j= 1;j<=ms;j++){
			f[i][j]= (s(i-1,j-1)-s(i-1,j-m-1)-(s(i-1,j-a[i])-s(i-1,j-a[i]-1)))/(m-1);
			sum[i][j]= sum[i][j-1]+f[i][j];
		}
	printf("%.12lf",sum[n][k-1]+1);
	return 0;
}
