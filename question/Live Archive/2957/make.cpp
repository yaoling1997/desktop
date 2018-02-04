#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 100;
int a[maxn][maxn];
int n,m,i,x,y,T;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(2)+1;
	while (T--){
		memset(a,0,sizeof(a));
		n= random(3)+2;m= random(n*(n-1)/2)+1;
		do x= random(n)+1,y= random(n)+1;
		while (x==y);
		printf("%d %d %d %d %d\n",n,m,random(3)+1,x,y);
		for (i= 2;i<=n;i++){
			printf("%d %d\n",i-1,i);
			a[i-1][i]= a[i][i-1]= 1;
		}
		for (i= n+1;i<=m;i++){
			do x= random(n)+1,y= random(n)+1;
			while (x==y||a[x][y]);
			a[x][y]= a[y][x]= 1;
			printf("%d %d\n",x, y);
		}			
	}return 0;
}
