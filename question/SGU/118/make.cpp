#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int M= 1e9;
int n,i,x,T;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= 5;
	printf("%d\n",T);
	while (T--){
		n= 1000;
		printf("%d ",n);
		for (i= 1;i<=n;i++)
			printf("%d%c",random(M)+1,i<n?' ':'\n');
	}return 0;
}
