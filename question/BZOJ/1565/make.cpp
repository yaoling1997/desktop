#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int maxn= 50;
int a[maxn][maxn];
int n,m,i,j,k,x,y,z,w;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	//n= random(2)+1;m= random(2)+1;
	//n= random(10)+2;m= random(5)+3;
	n= 7;m= 12;
	printf("%d %d\n",n, m);
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++){
			w= random(min(5,n*m));
			printf("%d %d",random(30),w);
			memset(a,0,sizeof(a));
			a[i][j]= 1;
			for (k= 1;k<=w;k++){
				do x= random(n),y= random(m);
				while (a[x][y]);
				a[x][y]= 1;
				printf(" %d %d",x, y);
			}printf("\n");
		}
	}return 0;	
}
