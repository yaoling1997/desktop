#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 300;
int a[maxn][maxn];
int n,m,mo,i,j,x,y;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(10)+2;m= random(30)+2;
	printf("%d %d %d\n",n, m, 10000000);
	for (i= 1;i<=m;i++){
		do x= random(n)+1,y= random(n)+1;
		while (a[x][y]);
		printf("%d %d\n",x, y);
		a[x][y]= 1;
	}return 0;
}
