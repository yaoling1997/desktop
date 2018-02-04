#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 300,sig= 3;
int a[maxn][maxn];
int n,i,j,x,y;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	//n= random(3)+3;
	n= 5;
	printf("%d\n",n);
	for (i= 2;i<=n;i++){
		x= random(i-1)+1;
		a[x][i]= a[i][x]= 1;
		printf("%d %d %d\n",x, i, random(sig)+1);
	}
	do x= random(n)+1,y= random(n)+1;
	while (x==y||a[x][y]);
	printf("%d %d %d\n",x, y, random(sig)+1);
	return 0;
}
