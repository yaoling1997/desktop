#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int sig= 10;
int n,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 10;
	printf("%d %d %d\n",n, n-1, 10000008);
	for (i= 2;i<=n;i++)
		printf("%d %d\n",i,random(i-1)+1);
	return 0;
}
