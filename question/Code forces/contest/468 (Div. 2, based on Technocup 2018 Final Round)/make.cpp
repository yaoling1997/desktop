#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int n,m,i,j,x,y,z;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n=100;m=1000;
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;i++){
		y=random(m)+1;
		x=random(y)+1;
		printf("%d %d\n",x, y);
	}
}