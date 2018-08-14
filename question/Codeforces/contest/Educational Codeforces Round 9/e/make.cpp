#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
int n,i,x,k,M= 1000;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= M;k= M;
	printf("%d %d\n",n, k);
	for (i= 1;i<=n;i++)
		printf("%d%c",random(M)+1,i<n?' ':'\n');
}
