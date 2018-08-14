#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
int n,i,x,M= 50;
int R(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= R(50)+1;
	printf("%d\n",n);
	printf("%d %d %d\n",R(M)+1,R(M)+1,R(M)+1);
	for (i= 1;i<=n;i++)
		printf("%d%c",R(M)+1,i<n?' ':'\n');
	return 0;
}
