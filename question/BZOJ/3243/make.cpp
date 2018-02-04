#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int sig= 5;
int n,d,i,j,x,K;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(10)+1;d= random(10)+1;K= 3;
	printf("%d %d %d\n",n, d, K);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=d;j++)
			printf("%d%c",random(2),j<d?' ':'\n');
	return 0;
}
