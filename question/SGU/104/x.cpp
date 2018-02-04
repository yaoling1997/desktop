#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 200,oo= 2e9;
int f[maxn][maxn],A[maxn][maxn],p[maxn][maxn];
int F,V,i,j,k,ans;
void print(int o,int x){
	if (!o) return;
	print(o-1,p[o][x]);
	printf("%d",x);
	if (o!=F) printf(" ");
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	memset(f,128,sizeof(f));
	f[0][0]= 0;
	ans= -oo;
	scanf("%d%d",&F, &V);
	for (i= 1;i<=F;i++)
		for (j= 1;j<=V;j++)
			scanf("%d",&A[i][j]);
	for (i= 1;i<=F;i++)
		for (j= 1;j<=V;j++)
			for (k= 0;k<j;k++){
				int &x= f[i][j],y= f[i-1][k],w= A[i][j];
				if (x<y+w){
					x= y+w;
					p[i][j]= k;
				}
			}
	j= 0;
	for (i= 1;i<=V;i++)
		if (f[F][j]<f[F][i])
			j= i;
	ans= f[F][j];
	printf("%d\n",ans);
	print(F,j);
	return 0;
}	
