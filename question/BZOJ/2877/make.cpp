#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 2;
int random(int o){return rand()%o;}
int xx,yy,x,y,X,Y,i,j,n,m,T;
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	//n= random(4)+1;m= random(3)+1;
	n= 10;m= 10;
	if (n>m) swap(n,m);
	xx= random(n)+1;yy= random(m)+1;
	T= random(50)+1;
	printf("%d %d\n%d %d\n%d\n",n, m, xx, yy, T);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			printf("%d%c",random(3)+1,j<m? ' ':'\n');
	for (i= 1;i<=T;i++){
		x= random(2);
		printf("%d ",x);
		if (x){
			x= random(n)+1;y= random(m)+1;
			printf("%d %d %d %d %d\n",random(x)+1,
				   random(y)+1, x, y, random(sig)+1);
		}else {
			printf("%d %d %d %d\n",random(xx),random(yy),
				   random(n-xx+1), random(m-yy+1));
		}
	}return 0;
}
