#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
int tt;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb T;ftime(&T);
	srand(T.time*1000+T.millitm);
	int p,q,r,s,t,u;
	tt= random(3)+1000;
	while (tt--){
		p= random(21);r= random(21);
		q= s= t= -random(21);u= random(10)-random(5);
		printf("%d %d %d %d %d %d\n",p,q,r,s,t,u);
	}
	return 0;
}
