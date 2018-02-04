#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
int T,i,j,l,n,p,x;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(1)+1;
	printf("%d\n",T);
	for (int a1= 1;a1<=T;a1++){
		n= 500;l= random(10)+2;p= random(5)+2;
		printf("%d %d %d\n",n, l, p);
		for (i= 1;i<=n;i++){
			x= random(10)+2;
			for (j= 1;j<=x;j++)
				printf("%c",'a');
			printf("\n");
		}
	}return 0;
}
