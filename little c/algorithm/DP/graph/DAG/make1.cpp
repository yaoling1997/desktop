#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
const int sig= 5;
int n,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 5;
	printf("%d\n",n);
	for (i= 1;i<=n;i++)
		printf("%d %d\n",random(sig)+1,random(sig)+1);
	return 0;
}
