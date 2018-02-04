#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
const int sig= 6;
int n,i,T,F;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(3)+2;F= random(5)+1;
	printf("%d %d\n",T, F);
	for (int a1= 1;a1<=T;a1++){
		n= random(3)+1;
		printf("%d\n",n);
		for (i= 1;i<=n;i++)
			printf("%d ",random(sig));
		printf("\n");
	}return 0;	
}
