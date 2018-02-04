#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 300,sig= 3;
int a[maxn][maxn],b[maxn][maxn];
int n,m,i,j,d,cnt,tot,x,y;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(5)+1;m= random(5)+1;d= random(2)+1;
	printf("%d %d %d\n",n, m, d);
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++){
			a[i][j]= random(3);
			if (a[i][j]) cnt++;
			printf("%d",a[i][j]);
		}printf("\n");
	}
	if (cnt)
		tot= random(cnt)+1;
	for (i= 1;i<=tot;i++){
		do x= random(n)+1,y= random(m)+1;
		while (b[x][y]||!a[x][y]);
		b[x][y]= 1;		
	}
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++)
			if (b[i][j])
				printf("L");
			else printf(".");
		printf("\n");
	}return 0;
}
