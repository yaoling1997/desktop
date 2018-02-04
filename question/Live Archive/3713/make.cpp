#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 200,sig= 200;
int n,x,y,i,m,T;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= 2;
	while (T--){
		n= random(2)+3;m= random(4)+1;
		printf("%d %d\n",n, m);
		for (i= 1;i<=n;i++)
			printf("%d\n",random(sig)+1);
		for (i= 1;i<=m;i++){
			x= random(n)+1,y= random(n)+1;
			printf("%d %d\n",x, y);
		}
	}
	printf("0 0\n");
	return 0;
}
