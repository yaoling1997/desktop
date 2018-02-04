#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
int T,n,i,j;
double random(double o){
	return (double)rand()/RAND_MAX*o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(3)+1;
	T= 1;
	for (int a1= 1;a1<=T;a1++){
		n= random(5)+1;
		printf("%d\n",n);
		for (i= 1;i<=n;i++){
			for (j= 1;j<=3;j++)
				printf("%lf ",random(5));
			printf("\n");
		}
	}
	printf("0");
	return 0;
}
