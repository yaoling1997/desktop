#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int sig= 60;
int i,n,T,x;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(2)+1;
	printf("%d\n",T);
	for(int a1= 1;a1<=T;a1++){
		n= random(5)+3;
		printf("%d\n",n);
		for (i= 1;i<=n;i++){
			printf("%d ",random(sig));
			x= random(2);
			if (x) printf("M ");
			else printf("F ");
			printf("%c %c\n",random(3)+65, random(3)+65);
		}
	}return 0;
}
