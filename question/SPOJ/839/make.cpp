#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int sh[maxn];
int n,m,i,j,x,y,z,T,k;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(2)+1;
	printf("%d\n",T);
	while (T--){
		n= random(6)+1;m= random(15)+2;
		for (i= 1;i<=n;i++)
			sh[i]= i;
		random_shuffle(sh+1,sh+n+1);
		printf("%d %d\n",n, m);
		for (i= 1;i<=m;i++){
			x= random(n)+1;
			y= random(n)+1;
			printf("%d %d\n",x, y);
		}
		k= random(n)+1;
		printf("%d\n",k);
		for (i= 1;i<=k;i++)
			printf("%d %d\n",sh[i], random(20));
		printf("\n");
	}return 0;
}
