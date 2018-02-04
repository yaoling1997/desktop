#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
int n,m,i,x,y;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(30)+2;m= random(30)+1;
	printf("%d %d\n",n, m);
	for (i= 1;i<=n;i++)
		printf("%d%c",random(30)+1, i<n?' ':'\n');
	for (i= 1;i<=m;i++){
		y= random(n)+1;
		printf("%d %d\n",random(y)+1, y);
	}return 0;
}
