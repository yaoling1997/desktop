#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 10;
int n,S,i;
double random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(10)+15;S= random(1000)+2;
	printf("%d %d\n",n, S);
	for (i= 1;i<=n;i++){
		printf("%lf %lf %lf\n",random(sig)+1, random(sig)+1, random(sig)+1);
	}return 0;
}
