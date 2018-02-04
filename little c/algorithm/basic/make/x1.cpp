#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
int main()
{
	freopen("1.out","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.millitm+t.time*1000);
	printf("%d",rand());
	return 0;
}
