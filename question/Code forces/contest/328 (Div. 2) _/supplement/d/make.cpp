#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3e5;
int b[maxn];
int n,m,i,x;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(50)+1;m= random(n)+1;
	printf("%d %d\n",n, m);
	for (i= 2;i<=n;i++)
		printf("%d %d\n",random(i-1)+1, i);
	for (i= 1;i<=m;i++){
		do x= random(n)+1;
		while (b[x]);
		b[x]= 1;
		printf("%d%c",x, i<m?' ':'\n');
	}return 0;
}