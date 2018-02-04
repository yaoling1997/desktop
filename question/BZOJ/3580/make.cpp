#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 10;
int n,K,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(4)+2;K= random(5);
	printf("%d %d\n",n, K);
	for (i= 1;i<=n;i++) printf("%d ",random(sig));
	return 0;
}
