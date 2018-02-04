#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
struct point{
	int x,y;
};
point a[200][200],P;
int o[200][200];
int n,m,q,i,j,x,y,z;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &m, &q);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			a[i][j]= (point){i,j};
	for (int qq= 1;qq<=q;qq++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d",&x);
			P= a[x][1];
			for (i= 2;i<=m;i++)
				a[x][i-1]= a[x][i];
			a[x][m]= P;
		}else if (x==2){
			scanf("%d",&x);
			P= a[1][x];
			for (i= 2;i<=n;i++)
				a[i-1][x]= a[i][x];
			a[n][x]= P;			
		}else {
			scanf("%d%d%d",&x, &y, &z);
			o[a[x][y].x][a[x][y].y]= z;
		}
	}
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			printf("%d%c",o[i][j], j<m?' ':'\n');
	return 0;
}