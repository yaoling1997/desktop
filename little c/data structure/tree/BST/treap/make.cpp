#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int oo= 10;
int n,i;
int random(int o){return rand()&o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 10;
	printf("%d\n",n);
	for (i= 1;i<=n;i++)
		printf("%d ",random(oo)-oo/2);
	return 0;
}
