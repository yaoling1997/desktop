#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
const int maxn= 1000,sig= 400;
int a[maxn][maxn];
int i,n,x,y;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(3)+2000;
	printf("%d\n",n);
	for (i= 1;i<=n;i++){
		do x= random(sig),y= random(sig);
		while (a[x][y]);
		a[x][y]= 1;
		printf("%d %d\n",x,y);
	}
	return 0;
}
