#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
#define ll long long
using namespace std;
const ll sig= 1e15;
int n,i,T;
int random(int o){return rand()%o;}
ll random(ll o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(3)+10;
	printf("%d\n",T);
	for (int a1= 1;a1<=T;a1++){
		n= 100;
		printf("%d\n",n);
		for (i= 1;i<=n;i++)
			printf("%lld ",random(sig)+1);
		printf("\n");
	}
	return 0;
}
