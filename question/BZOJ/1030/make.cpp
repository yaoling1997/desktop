#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001;
int n,m,i,j,x;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(40)+2;m= random(5)+10;
	printf("%d %d\n",n, m);
	for (i= 1;i<=n;i++){
		int len= random(5)+3;
		for (j= 1;j<=len;j++)
			printf("%c",random(2)+'A');
		printf("\n");
	}return 0;		
}
