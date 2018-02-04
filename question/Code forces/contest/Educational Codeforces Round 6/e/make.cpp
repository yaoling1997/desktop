#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int n,m,i,j,x,y,z,M= 4e5;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(M)+1;m= random(M)+1;
	printf("%d %d\n",n, m);
	for (i= 1;i<=n;i++)
		printf("%d%c",random(2)+1,i<n?' ':'\n');
	for (i= 2;i<=n;i++)
		printf("%d %d\n",i, random(i-1)+1);
	for (i= 1;i<=m;i++){
		x= random(2)+1;
		if (x==1){
			printf("%d %d %d\n",x, random(n)+1, random(2)+1);
		}else {
			printf("%d %d\n",x, random(n)+1);
		}
	}
}
