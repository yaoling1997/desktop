#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int M= 2e5,MM= 10;
int n,m,i,x,y,z;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= M;m= random(n)+1;
	printf("%d %d\n",n, m);
	for (i= 2;i<=n;i++)
		printf("%d %d %d\n",random(i-1)+1,i,random(5)+1);
	for (i= 1;i<=m;i++){
		x= random(2)+1;
		printf("%d ",x);
		if (x==1){
			x= random(n)+1;y= random(n)+1;
			z= random(MM)+1;
			printf("%d %d %d\n",x, y, z);
		}else {
			x= random(n-1)+1;y= random(MM)+1;
			printf("%d %d\n",x, y);
		}
	}return 0;
}
