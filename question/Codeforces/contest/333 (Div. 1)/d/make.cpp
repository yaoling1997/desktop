#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
int n,i,x;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 7;
	printf("%d\n",n);
	for (i= 1;i<=n;i++)
		printf("%d%c",random(5),i<n?' ':'\n');
	for (i= 1;i<=n;i++)
		printf("%c",random(20)+97);
	printf("\n");
	for (i= 2;i<=n;i++)
		printf("%d %d\n",random(i-1)+1,i);
	return 0;
}
