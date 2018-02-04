#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
int T,n,i,x;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= 2;
	printf("%d\n",T);
	while (T--){
		n= random(3000)+30000;
		printf("%d\n",n);
		for (i= 1;i<=n;i++)
			printf("%d%c",random(100000)+1,i<n?' ':'\n');
	}return 0;
}
