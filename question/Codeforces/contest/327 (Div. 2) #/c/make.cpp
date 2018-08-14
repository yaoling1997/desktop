#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<sys/timeb.h>
using namespace std;
int n,i;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(500)+3;
	printf("%d\n",n);
	for (i= 1;i<=n;i++)
		printf("%d%c",random(2),i<n?' ':'\n');
	return 0;
}
