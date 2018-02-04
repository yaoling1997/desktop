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
	T= random(3)+2;
	while (T--){
		n= random(5)+1;
		printf("%d\n",n);
		for (i= 1;i<=n;i++){
			x= random(5)+3;
			for (j= 1;j<=x;j++)
				printf("%c",random(2)+'a');
			printf("\n");
		}
	}
	printf("0");
	return 0;
}
