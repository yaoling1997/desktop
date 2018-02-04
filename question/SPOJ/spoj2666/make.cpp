#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int n,m,i,j,x,y,z,M= 2000;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(10)+1;
	printf("%d\n",n);
	for (i= 2;i<=n;i++)
		//printf("%d %d %d\n",i-1,i,random(M)-M/2);
		printf("%d %d %d\n",random(i-1)+1,i,random(M)-1000);
	m= random(100000)+1;
	printf("%d\n",m);
	for (i= 1;i<=m;i++){
		x= random(2);
		if (!x){
			printf("C %d\n",random(n)+1);
		}else {
			printf("A\n");
		}
	}return 0;
}
