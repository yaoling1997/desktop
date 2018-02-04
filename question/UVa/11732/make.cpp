#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 2,sig1= 1000;
int T,n,i,j,len;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= 1;
	for (int a1= 1;a1<=T;a1++){
		n= random(5)+400;
		printf("%d\n",n);
		for (i= 1;i<=n;i++){
			len= random(sig1)+1;
			for (j= 1;j<=len;j++)
				printf("%c",random(sig)+65);
			printf("\n");
		}
	}
	printf("0");
	return 0;
}
