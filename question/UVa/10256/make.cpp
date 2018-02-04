#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int sig= 10;
int n,m,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 5;m= 5;
	for (int t= 1;t<=10;t++){
		printf("%d %d\n",n, m);
		for (i= 1;i<=n;i++)
			printf("%d %d\n",random(sig),random(sig));
		for (i= 1;i<=m;i++)
			printf("%d %d\n",random(sig)+10,random(sig))+10;
	}
	printf("0 0\n");
	return 0;
}
