#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int n,m,i,j,x,y,z;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 8;
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
		printf("%d%c",random(2)+1,i<n?' ':'\n');
	return 0;
}
