#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3000;
int a[maxn][maxn];
int x,y,n,m,s,i,j;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(30)+5;m= random(30)+5;//s= random(n*m)+1;
	s= random(n*m)+1;
	printf("%d %d\n",n,m);
	for (i= 1;i<=s;i++){
		do x= random(n)+1,y= random(m)+1;
		while (a[x][y]);
		a[x][y]= 1;
	}
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++){
			if (a[i][j])
				printf("R");
			else printf("F");
			if (j!=m) printf(" ");
			else printf("\n");
		}
	return 0;
}
