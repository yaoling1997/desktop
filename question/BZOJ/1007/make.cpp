#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int sig= 5000,maxn= 10000;
int a[maxn][maxn];
int i,n,x,y;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 50000;
	printf("%d\n",n);
	for (i= 1;i<=n;i++){
		do x= random(sig),y= random(sig);
		while (a[x][y]);
		a[x][y]= 1;
		printf("%d %d\n",x, y);
	}
	return 0;
}
