#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
int n,l,k,i,j,x,y,z;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(50)+1;l= random(50)+1;k= random(50)+1;
	printf("%d %d %d\n",n, l, k);
	for (i= 1;i<=n;i++)
		printf("%d%c",random(9)+1,i<n?' ':'\n');
}
