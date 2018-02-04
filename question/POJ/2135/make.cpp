#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 5;
int n,m,i,x,y;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(3)+1;m= random(2*n)+1;
	printf("%d %d\n",n, m);
	for (i= 1;i<=m;i++){
		printf("%d %d %d\n",random(n)+1,random(n)+1,random(sig));
	}return 0;
}
