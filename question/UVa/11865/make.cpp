#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 50;
int n,m,i,T,cost;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(3)+1;
	printf("%d\n",T);
	for (int a1= 1;a1<=T;a1++){
		n= random(3)+10;m= random(10)+50;cost= random(4*sig)+1;
		printf("%d %d %d\n",n,m,cost);
		for (i= 1;i<=m;i++){
			printf("%d %d %d %d\n",random(n),
				   random(n),random(sig),random(sig));
		}
	}
	return 0;
}
