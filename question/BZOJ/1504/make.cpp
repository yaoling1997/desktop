#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 3;
int n,w,T,V,i,x,y,z;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 2;w= random(5)+2;T= random(3)+1;V= 1;
	printf("%d %d %d %d\n",n, w, T, V);
	for (i= 1;i<=n;i++){
		x= random(w);y= random(w-x)+1;z= random(sig)-sig/2;
		printf("%d %d %d\n",x, y, z);
	}return 0;
}
