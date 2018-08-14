#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int n,m,i,j,x,y,x0,y0,M= 10;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(10)+1;
	printf("%d\n",n);
	for (i= 1;i<=n;i++){
		x= random(2);
		if (x==0){
			x= random(M);
			y= random(M);
			y0= random(M);
			printf("%d %d %d %d\n",x, y, x, y0);
		}else {
			x= random(M);
			x0= random(M);
			y= random(M);
			printf("%d %d %d %d\n",x, y, x0, y);
		}
	}return 0;
}
