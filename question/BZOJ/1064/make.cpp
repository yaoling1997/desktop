#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001;
int n,m,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(40)+4;m= random(n)+1;
	printf("%d %d\n",n, m);
	for (i= 1;i<=m;i++)
		printf("%d %d\n",random(n)+1,random(n)+1);
	return 0;
}
