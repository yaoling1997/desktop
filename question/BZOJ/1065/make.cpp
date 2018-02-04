#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
double K;
int n,m,i,j,x;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 4;m= 1;K= 0.5;
	printf("%d %d %.1lf\n",n, m, K);
	printf("%d ",random(n-1)+2);
	for (i= 2;i<=n;i++){
		x= random(i-1)+1;
		printf("%d%c",x,i<n?' ':'\n');
	}
	for (i= 1;i<=n;i++)
		printf("%d%c",random(5)+1,i<n?' ':'\n');
	return 0;
}
