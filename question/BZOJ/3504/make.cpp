#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 100,sig= 3;
char a[maxn][maxn];
int n,m,x,y,z,i,j,T;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(3)+1;
	for (int a1= 1;a1<=T;a1++){
		n= random(3)+2;
		printf("%d %d %d %d %d %d %d\n",n,random(n),random(n),random(sig),random(n),random(n),random(sig));
		for (i= 1;i<=n;i++)
			for (j= i;j<=n;j++)
				if (i==j){
					a[i][j]= 'X';
				}else {
					x= random(3)+1;
					if (x==1) a[i][j]= 'X';
					else if (x==2) a[i][j]= 'N';
					else a[i][j]= 'O';
					a[j][i]= a[i][j];
				}
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++)
				if (j!=n)
					printf("%c ",a[i][j]);
				else printf("%c\n",a[i][j]);
	}return 0;
}
