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
	n= random(50)+1;m=random(2)+1;
	printf("%d %d\n",n, m);
	for (int j=1;j<=2;j++)
		for (int i=1;i<=n;i++)
			printf("%d%c",random(m),i<n?' ':'\n');
	return 0;
	
}
