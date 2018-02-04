#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 10;
int a[maxn];
int n,i,x,q,m;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 100;
	printf("%d\n",n);
	for (i= 1;i<=n;i++) a[i]= i;
	for (i= 2;i<=n;i++)
		printf("%d %d\n",random(i-1)+1,i);
	q= 10;
	printf("%d\n",q);
	for (int a1= 1;a1<=q;a1++){
		m= random(n)+1;
		printf("%d\n",m);
		random_shuffle(a+1,a+n+1);
		for (i= 1;i<=m;i++) printf("%d%c",a[i],i<m?' ':'\n');
	}return 0;
}
