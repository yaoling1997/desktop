#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 200000,sig= 100000;
int a[maxn];
int n,i,x,y,T;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(5)+1;
	for (int a1= 1;a1<=T;a1++){
		memset(a,0,sizeof(a));		
		n= random(13)+200;printf("%d\n",n);
		for (i= 1;i<=n;i++){
			do x= random(sig),y= random(sig);
			while (a[x]||a[y]);
			a[x]= a[y]= 1;
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}
