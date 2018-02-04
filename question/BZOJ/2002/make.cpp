#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int sig= 200000;
int i,n,m;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 200000;printf("%d\n",n);
	for (i= 1;i<=n;i++)
		printf("%d ",random(sig)+1);
	printf("\n");
	m= 100000;
	printf("%d\n",m);
	for (i= 1;i<=m;i++){
		int x= random(2)+1;
		printf("%d ",x);
		if (x==2)
			printf("%d %d\n",random(n),random(sig)+1);
		else printf("%d\n",random(n));
	}
	return 0;
}
