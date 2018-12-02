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
const int maxn= 105,oo=1e9;
int f[105][105][5][5];
int n,ans;
void update(int &x,int y){
	x=max(x,y);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=0;i<105;i++)
		for (int j=0;j<105;j++)
			for (int k=0;k<5;k++)
				for (int z=0;z<5;z++)
					f[i][j][k][z]=-oo;
	for (int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&z,&y);
		f[i][i][x][y]=f[i][i][y][x]=z;
		update(ans,f[i][i][x][y]);
	}
	for (int i=n-1;i;i--)
		for (int j=i+1;j<=n;j++)
			for (int p=1;p<=4;p++)
				for (int q=1;q<=4;q++)
					for (int k=i;k<j;k++){
						update(f[i][j][p][q],max(f[i][k][p][q],f[k+1][j][p][q]));
						for (int r=1;r<=4;r++){
							update(f[i][j][p][q],f[i][k][p][r]+f[k+1][j][r][q]);
							update(f[i][j][p][q],f[i][k][r][q]+f[k+1][j][p][r]);
						}
						if (ans<f[i][j][p][q])
							ans= f[i][j][p][q];
					}
	printf("%d",ans);
	return 0;
}
