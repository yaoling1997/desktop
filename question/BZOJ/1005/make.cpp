#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
int n,i,x;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 10;
	printf("%d\n",n);
	for (i= 1;i<=n;i++){
		x= random(2);
		if (x){
			printf("%d\n",random(3)+2);
		}else {
			printf("-1\n");
		}
	}return 0;
}
