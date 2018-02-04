#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 30001,sig= 100000;
int a[maxn];
int n,m,i,x,y,sum;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(10000)+2;m= random(10000)+2;
	printf("%d %d\n",n, m);
	printf("1 1 %d %d\n",n, random(sig));
	for (i= 1;i<=n;i++) a[i]++;
	for (int a1= 2;a1<=m;a1++){
		x= random(2)+1;
		printf("%d ",x);
		if (x==1){
			y= random(n)+1;x= random(y)+1;
			printf("%d %d %d\n",x, y, random(sig)+1);
			for (i= x;i<=y;i++)
				a[i]++;
		}else {
			y= random(n)+1;x= random(y)+1;
			sum= 0;
			for (i= x;i<=y;i++)	sum+= a[i];
			printf("%d %d %d\n",x, y, random(sum)+1);
		}
	}
	return 0;
}
