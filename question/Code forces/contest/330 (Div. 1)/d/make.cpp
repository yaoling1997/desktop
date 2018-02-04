#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
int n,i,x,M= 1e6,q;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 2e5;
	printf("%d\n",n);
	for (i= 1;i<=n;i++)
		printf("%d%c",random(M),i<n?' ':'\n');
	q= 2e5;
	for (i= 1;i<=n;i++){
		x= random(n)+1;
		printf("%d %d\n",random(x)+1,x);
	}
	return 0;
}
