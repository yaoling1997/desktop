#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
int n,m,i,x,y;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(5)+20000;m= random(5)+10000;
	printf("%d %d\n",n,m);
	for (i= 1;i<=n;i++)
		printf("%d ",random(n)+1);
	printf("\n");
	for (i= 1;i<=m;i++){
		y= random(n-1)+2;x= random(y-1)+1;
		printf("%d %d\n",x,y);
	}
	return 0;
}
