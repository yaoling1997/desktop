#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 5;
int n,m,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	//n= random(4)+2;m= random(n);
	n= random(10)+2;m= random(n);
	printf("%d %d\n",n, m);
	for (i= 1;i<=n;i++)
		printf("%d\n",random(sig)+1);
	return 0;
}
