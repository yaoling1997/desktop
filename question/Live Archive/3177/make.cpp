#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
int sig= 10,maxn= 100;
int T,i,n;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	//T= random(5)+1;
	T= 2;
	for (int a1= 1;a1<=T;a1++){
		n= random(6)+1;printf("%d\n",n);
		for (i= 1;i<=n;i++)
			printf("%d\n",random(sig));		
	}printf("0");return 0;
}
