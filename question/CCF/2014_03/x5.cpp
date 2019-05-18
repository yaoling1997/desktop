#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
const int maxn= 50,maxm= 500,oo= 1e9,M= 400;
int f[maxn][maxm][maxm];
int a[maxn],b[maxn],c[maxn],d[maxn];
int n,i,ans;
void update(int &F,int x){
	F= min(F,x);
}
int max(int x,int y,int z){
	return max(max(x,y),z);
}
int solve(){
	int i,j,k,x;
	for (i= 0;i<=n;i++)
		for (j= 0;j<=M;j++)
			for (k= 0;k<=M;k++)
				f[i][j][k]= oo;
	f[0][0][0]= 0;
	for (i= 1;i<=n;i++)
		for (j= 0;j<=M;j++)
			for (k= 0;k<=M;k++){				
				if (f[i-1][j][k]==oo)
					continue;
				//CPU1
				update(f[i][j+a[i]][k],f[i-1][j][k]);
				//CPU2
				update(f[i][j][k+a[i]],f[i-1][j][k]);
				//CPU1,CPU2
				x= max(j,k)+b[i];
				update(f[i][x][x],f[i-1][j][k]);
				//CPU1,GPU
				x= max(f[i-1][j][k],j)+c[i];
				update(f[i][x][k],x);
				//CPU2,GPU
				x= max(f[i-1][j][k],k)+c[i];
				update(f[i][j][x],x);
				//CPU1,CPU2,GPU
				x= max(j,k,f[i-1][j][k])+d[i];
				update(f[i][x][x],x);
			}
	int re= oo;
	for (i= 0;i<=M;i++)
		for(j= 0;j<=M;j++)
			re= min(re,max(i,j,f[n][i][j]));
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
	ans= solve();
	printf("%d",ans);
	return 0;
}

