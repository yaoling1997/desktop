#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 20;
int n,K,p;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(25)+2;K= random(20)+2;p= random(1000)+2;
	printf("%d %d %d\n",n, K, p);
	return 0;
}
