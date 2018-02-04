#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int sig=  500000;
int n,i,j;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 10;
	printf("%d\n",n);n= 1<<n;
	for (i= 1;i<=n;i++)
		printf("%d%c",random(2),i<n? ' ':'\n');
	for (i= 1;i<=n;i++)
		printf("%d%c",random(sig),i<n? ' ':'\n');	
	for (i= 1;i<n;i++){
		for (j= n;j>i;j--)
			printf("%d ",random(sig));
		printf("\n");
	}
	return 0;
}
