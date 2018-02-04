#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001;
int n,sum,i,x;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(3)+2;
	printf("%d\n",n);sum= 10*n;
	for (i= 1;i<n;i++){
		if (sum){
			x= random(sum)+1;
			printf("%d\n",x);
			sum-= x;
		}
		else printf("0\n");
	}printf("%d\n",sum);
	return 0;
}
