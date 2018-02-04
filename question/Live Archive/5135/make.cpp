#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 1001;
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
	T= random(150)+5;
	while (T--){
		n= random(20)+5;
		m= n-1+random(n*(n-1)/2-n+1+1);
		//m= n-1;
		m= min(m,50000);
		memset(a,0,sizeof(a));
		printf("%d\n",m);
		for (i= 2;i<=n;i++){
			printf("%d %d\n",i-1, i);
			a[i-1][i]= a[i][i-1]= 1;
		}
		for (i= n;i<=m;i++){
			do x= random(n)+1,y= random(n)+1;
			while (x==y||a[x][y]);
			a[x][y]= a[y][x]= 1;
			printf("%d %d\n",x, y);
		}
	}printf("0");
	return 0;
}
