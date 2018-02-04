#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
int n,l,s,i,j;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(4)+100;l= random(3)+2;s= 64;
	printf("%d %d %d\n",n, l, s);
	for (i= 1;i<=n;i++){
		for (j= 1;j<=l;j++)
			printf("%c",random(2)+65);
		printf("\n");
	}return 0;
}
