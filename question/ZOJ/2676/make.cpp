#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 500;
int a[maxn][maxn];
int n,m,i,j,x,y,z,T;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(5)+1;
	//T= 1;
	while (T--){
		//n= 30;
		//n= 100;
		//m= random(400)+n-1;
		n= random(4)+2;
		m= random(3)+n-1;
		m= min(m,n*(n-1)/2);
		printf("%d %d\n",n, m);
		memset(a,0,sizeof(a));
		for (i= 2;i<=n;i++){
			a[i-1][i]= a[i][i-1]= 1;
			printf("%d %d %d\n",i-1, i, random(3)+1);
		}
		for (i= n;i<=m;i++){
			do x= random(n)+1,y= random(n)+1;
			while (x==y||a[x][y]);
			a[x][y]= a[y][x]= 1;
			printf("%d %d %d\n",x, y, random(1e7)+1);
		}
	}return 0;
}
