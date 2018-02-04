#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
int n,i,x,m;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 8;m= 2;
	printf("%d %d\n",n, m);
	for (i= 1;i<=n;i++)
		printf("%d%c",random(10),i<n?' ':'\n');
	for (i= 1;i<=m;i++)
		printf("%d %d\n",random(2)+1,random(n)+1);	
}
