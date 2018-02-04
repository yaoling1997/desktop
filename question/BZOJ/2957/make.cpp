#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 8;
int n,m,i,j,x,y;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(4)+2;m= random(3)+2;
	printf("%d %d\n",n,m);
	for (int a1= 1;a1<=m;a1++){
		x= random(n)+1;y= random(sig);
		printf("%d %d\n",x, y);
	}
	return 0;
}
