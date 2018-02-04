#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001;
int T,n,m,i,j,x;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(5)+2;
	printf("%d\n",T);
	for (int a1= 1;a1<=T;a1++){
		n= random(4)+1;m= random(2)+n;
		printf("%d %d\n",n, m);
		for (i= 2;i<=n;i++)
			printf("%d %d %d\n",random(i-1)+1, i, random(2));
		for (i= n;i<=m;i++)
			printf("%d %d %d\n",random(n)+1, random(n)+1 ,random(2));
	}return 0;
}
