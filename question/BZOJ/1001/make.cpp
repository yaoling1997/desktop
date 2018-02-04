#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int sig= 100000;
int n,m,i,j;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(2)+2;m= random(2)+2;
	//n= 100;m= 100;
	n= 2;m= 2;
	printf("%d %d\n",n, m);
	for (i= 1;i<=n;i++){
		for (j= 1;j<m;j++)
			printf("%d ",random(sig));
		printf("\n");
	}
	for (i= 1;i<n;i++){
		for (j= 1;j<=m;j++)
			printf("%d ",random(sig));
		printf("\n");
	}
	for (i= 1;i<n;i++){
		for (j= 1;j<m;j++)
			printf("%d ",random(sig));
		printf("\n");
	}return 0;	
}
