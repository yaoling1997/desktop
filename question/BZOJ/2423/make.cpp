#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001;
int n,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(3)+1;
	for (i= 1;i<=n;i++)
		printf("%c",65+random(2));printf(".\n");
	for (i= 1;i<=n;i++)
		printf("%c",65+random(2));printf(".\n");
	return 0;
}
