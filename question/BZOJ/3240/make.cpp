#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001;
int n,m,a,b,c,d;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(300)+1;m= random(300)+1;
	a= random(300)+1;b= random(300)+1;c= random(300)+1;
	d= random(300)+1;
	printf("%d %d %d %d %d %d",n, m, a, b, c, d);
	return 0;
}
