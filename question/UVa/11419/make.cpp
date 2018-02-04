#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 300;
int a[maxn][maxn];
int n,r,c,i,x,y,T;
int R(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= 1;
	while (T--){
		memset(a,0,sizeof(a));
		r= R(5)+1;c= R(5)+1;
		n= R(r*c)+1;
		printf("%d %d %d\n",r, c, n);
		for (i= 1;i<=n;i++){
			do x= R(r)+1,y= R(c)+1;
			while (a[x][y]);
			a[x][y]= 1;
			printf("%d %d\n",x, y);
		}
	}
	printf("0 0 0");
	return 0;
}
