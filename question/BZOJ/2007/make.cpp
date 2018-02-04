#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 5;
int n,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 2;printf("%d\n",n);
	for (i= 1;i<=4*n*(n+1);i++)
		printf("%d\n",random(sig));
	return 0;
}
