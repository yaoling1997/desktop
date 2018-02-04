#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 1000;
int n,i,T;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(5)+1;
	for (int a1= 1;a1<=T;a1++){
		n= random(3)+100;
		printf("%d\n",n);
		for (i= 1;i<=n;i++)
			printf("%d %d %d\n",random(sig)+1,random(sig)+1,random(sig)+1);
	}
	printf("0");
	return 0;
}
