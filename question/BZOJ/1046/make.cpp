#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 10;
int n,i,m;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(5)+2;printf("%d\n",n);
	for (i= 1;i<=n;i++)
		printf("%d ",random(sig));
	printf("\n");
	m= random(5)+1;printf("%d\n",m);
	for (i= 1;i<=m;i++){
		printf("%d\n",random(n)+1);
	}
	return 0;
}
