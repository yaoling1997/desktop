#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int n,m,i,j,x,y,z,T;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(40)+2;
	while (T--){
		n= random(50000)+2;
		printf("%d\n",n);
		for (i= 1;i<=n;i++)
			printf("%c",random(5)+'a');
		printf("\n");
	}printf("0");
	return 0;
}