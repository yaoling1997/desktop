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
	n= random(1000)+1;
	printf("%d\n",n);
	printf("%d",random(9)+1);
	for (i= 2;i<=n;i++)
		printf("%d",random(10));
	return 0;
}
