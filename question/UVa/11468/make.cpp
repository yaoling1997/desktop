#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001;
int i,j,K,T,len;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(3)+1;
	T= 1;
	printf("%d\n",T);
	for (int a1= 1;a1<=T;a1++){
		K= random(2)+2;
		printf("%d\n",K);
		for (i= 1;i<=K;i++){
			len= random(3)+1;
			for (j= 1;j<=len;j++)
				printf("%c",97+random(2));
			printf("\n");
		}
		printf("%d\n",2);
		for (j= 1;j<=2;j++)
			printf("%c %.1lf\n",96+j,0.5);
		printf("%d\n",random(2)+10);
		printf("\n");	
	}
	return 0;
}
