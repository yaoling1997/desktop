#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
int n,m,x,y,z,i;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 1000;m= random(500)+1;
	printf("%d %d\n",n, m);
	for (i= 2;i<=n;i++)
		printf("%d %d\n",i, random(i-1)+1);
	for (i= 1;i<=n;i++)
		printf("%d%c",random(30)+1,i<n?' ':'\n');
	printf("%d\n",random(n)+1);
	for (i= 1;i<=m;i++){
		x= random(3)+1;
		printf("%d ",x);
		if (x==1){
			printf("%d\n",random(n)+1);
		}else if (x==2){
			x= random(n)+1;y= random(n)+1;
			printf("%d %d %d\n",x,y,random(n)+1);
		}else {
			printf("%d\n",random(n)+1);
		}
	}return 0;
}
