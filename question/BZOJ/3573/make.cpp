#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 10,sig= 30;
int n,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	//n= random(10000)+2;
	n= 5e5;
	printf("%d\n",n);
	for (i= 1;i<=n;i++)
		printf("%d\n",random(sig)+1);
	for (i= 2;i<=n;i++)
		printf("%d %d\n",random(i-1)+1,i);
	return 0;
}
