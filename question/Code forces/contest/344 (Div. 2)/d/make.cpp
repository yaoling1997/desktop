#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<sys/timeb.h>
#define ll long long
using namespace std;
int n,m,i,j,k,x,y,z;
int R(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= R(1000)+1;m= 1;
	printf("%d %d\n",n, m);
	for (i= 1;i<=n;i++)
		printf("%d-%c ",R(3)+1,'a'+R(2));
	printf("\n");
	for (i= 1;i<=m;i++)
		printf("%d-%c ",R(3)+1,'a'+R(2));
}
