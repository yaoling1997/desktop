#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 200,oo= 1e9;
int f[maxn][maxn],sum[maxn],a[maxn],gl[maxn][maxn],gr[maxn][maxn];
int A,n,i,j,l,r;
void init(){
	memset(gl,0,sizeof(gl));
	memset(gr,0,sizeof(gr));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		if (!n) break;
		init();
		for (i= 1;i<=n;i++){
			scanf("%d",&a[i]);
			sum[i]= sum[i-1]+a[i];
			gl[i][i]= gr[i][i]= min(a[i],0);
			f[i][i]= a[i];
		}
		for (i= 2;i<=n;i++)
			for (j= 1;j+i-1<=n;j++){
				r= j+i-1;
				int x= min(gl[j+1][r],0);
				int y= min(gr[j][r-1],0);
				int m= min(x,y);				
				f[j][r]= sum[r]-sum[j-1]-m;
				gl[j][r]= min(gl[j+1][r],f[j][r]);
				gr[j][r]= min(gr[j][r-1],f[j][r]);
			}
		A= f[1][n];
		printf("%d\n",2*A-sum[n]);
	}return 0;
}
