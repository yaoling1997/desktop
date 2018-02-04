#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int n,m,i,j,x,y,z,K,T;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= 1;
	while (T--){
		//n= random(100)+1;
		n= 5000;
		K= random(1e7);
		printf("%d %d\n",n, K);
		for (i= 2;i<=n;i++)
			printf("%d %d %d\n",i-1,i,random(1000)+1);
	}printf("0 0");
	return 0;
}
