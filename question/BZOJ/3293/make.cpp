#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
int n,sum,i,x;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(10)+2;sum= (random(3)+1)*n;
	printf("%d\n",n);
	for (i= 1;i<n;i++){
		x= random(sum);
		sum-= x;
		printf("%d ",x);
	}printf("%d",sum);
	return 0;
}
