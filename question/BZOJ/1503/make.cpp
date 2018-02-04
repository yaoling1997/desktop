#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
const int sig= 10;
int i,n,v,x;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(10)+5;v= random(sig);
	printf("%d %d\n",n,v);
	while (n>1){
		x= random(4)+1;
		if (x==1){
			printf("I %d",random(sig));
		}else if (x==2){
			printf("A %d",random(sig));
		}else if (x==3){
			printf("S %d",random(sig));
		}else {
			printf("F %d",random(sig)+1);
		}
		printf("\n");n--;
	}
	printf("F %d",1);	
	return 0;
}
