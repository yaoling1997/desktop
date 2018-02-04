#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
using namespace std;
const int maxn= 3001,sig= 1000;
int random(int o){return rand()%o;}
int a,b,n,i,j;
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	a= 100;b= 100;n= 100;
	printf("%d %d %d\n",a,b,n);
	for (i= 1;i<=a;i++){
		for (j= 1;j<=b;j++)
			printf("%d ",random(2*sig)-sig);
		printf("\n");
	}
	return 0;
}
