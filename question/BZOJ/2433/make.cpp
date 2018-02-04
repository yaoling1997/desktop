#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001;
int n,i,j,x,y,z,l,r;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 3;
	printf("%d\n",n);
	x= 0;l= 0;r= 10;
	printf("%d %d %d %d\n",x, l, x+1, r);
	for (i= 2;i<=n;i++){
		x++;
		y= random(r);
		z= random(3)+1+l;
		if (z<y) swap(z,y);
		printf("%d %d %d %d\n",x, y, x+1, z);
		l= y;r= z;
	}printf("0 0\n");
	printf("%d %d\n",x+1,z);
	printf("1");
	return 0;
}
