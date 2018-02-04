#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
const int maxn= 8;
int a[maxn][maxn];
int n,m,i,j,x,y,x1,x2,y1,y2,t;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	x= random(16)+1;n= 4;m= 4;
	for (int t= 1;t<=2;t++){
		y= 0;
		for (i= 1;i<=n;i++)
			for (j= 1;j<=m;j++){
				if (x-y)
					a[i][j]= 1,y++;
				else a[i][j]= 0;
			}
		for (i= 1;i<=30;i++){
			x1= random(4)+1;y1= random(4)+1;
			x2= random(4)+1;y2= random(4)+1;
			swap(a[x1][y1],a[x2][y2]);
		}
		for (i= 1;i<=n;i++){
			for (j= 1;j<m;j++)
				printf("%d",a[i][j]);
			printf("%d\n",a[i][m]);
		}
		printf("\n");
	}
	return 0;
}
