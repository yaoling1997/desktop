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
	int n=random(10)+2,m= random(10)+1;
	printf("%d %d\n",n, m);
	for (int i=1;i<=m;i++)
		printf("%d %d %d\n",random(n)+1,random(n)+1,random(20)+1);
	for (int i= 1;i<=n;i++)
		printf("%d%c",random(20)+1,i<n?' ':'\n');
	return 0;
}
