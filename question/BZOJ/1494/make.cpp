#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
#define ll long long;
using namespace std;
const int maxn= 3001;
int k,n;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	k= 2;n= random(100)+3;
	printf("%d %d\n",k,n);
	return 0;
}
