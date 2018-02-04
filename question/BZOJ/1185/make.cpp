#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= random(2)+100;
	printf("%d\n",n);
	for (i= 1;i<=n;i++){
		printf("%lf %lf\n",random(1000)*1.0/10,random(1000)*1.0/10);
	}
	return 0;
}
