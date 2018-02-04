#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001;
const int sig= 5;
int n,i,x;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 40;
	printf("%d\n",n);
	for (i= 1;i<=n;i++){
		do x= random(n)+1;
		while (x==i);
		printf("%d %d\n",random(sig)+1,x);
	}return 0;
}
