#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
const int sig= 20;
int n,m,d,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 50;m= 1000;d= 10;
	printf("%d %d %d\n",d, n, m);
	for (i= 1;i<=d;i++)
		printf("%d ",random(sig)+1);
	printf("\n");
	for (i= 1;i<=d;i++)
		printf("%d ",random(sig)+1);printf("\n");
	printf("0 0 0");
	return 0;
}
