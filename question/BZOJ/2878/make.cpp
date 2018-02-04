#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int sig= 2;
int n,m,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(3)+2;m= n-1;
	printf("%d %d\n",n, m);
	for (i= 2;i<=n;i++)
		printf("%d %d %d\n",random(i-1)+1, i, random(sig)+1);
	return 0;
}
