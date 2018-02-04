#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
int n,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(2)+1;
	printf("%d\n",n);
	for (i= 1;i<=n;i++)
		printf("%d %d %d\n",random(5)+1,random(5),random(5));
	return 0;
}
