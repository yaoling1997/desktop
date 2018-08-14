#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int b[maxn];
int n,i,x,M= 7;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(5)+1;
	printf("%d\n",n);
	for (i= 1;i<=n;i++){
		do x= random(M);
		while (b[x]);
		b[x]= 1;
		printf("%d %d\n",x, random(4)+1);
	}return 0;
}
