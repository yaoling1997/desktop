#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn= 3001,sig= 10;
int n,i,l,r,x;
int a[maxn];
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 10;
	printf("%d\n",n);
	for (i= 1;i<=n;i++){
		r= random(sig)+2;l= random(r-1)+1;
		do x= random(sig)+1;
		while (a[x]);
		a[x]= 1;
		printf("%d %d %d\n",x,l,r);
	}
	return 0;
}
