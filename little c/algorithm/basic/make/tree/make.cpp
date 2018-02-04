#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001;
int par[maxn];
int n,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(5)+1;
	printf("%d\n",n);
	for (i= 2;i<=n;i++)
		par[i]= i-1;
	for (i= 2;i<=n;i++)
		par[i]= random(par[i])+1;
	for (i= 2;i<=n;i++)
		printf("%d %d\n",i,par[i]);
	return 0;
}
