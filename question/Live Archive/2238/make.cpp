#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int n,m,i,j,x,y,z,T,Max,k;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	//T= random(10)+2;
	T= 10;
	while (T--){
		Max= 0;
		//n= random(50)+1;
		//m= random(10)+1;
		n= 50;
		m= 10;
		//m= random(3)+1;
		//n= random(4)+1;
		printf("%d %d\n",m, n);
		for (i= 1;i<=m;i++){
			x= random(9)+1;
			Max= max(Max,x);
			printf("%d%c",x, i<m?' ':'\n');
		}
		for (i= 1;i<=n;i++){
			k= random(5)+1;
			//k= 1;
			printf("%d",k);
			x= random(5)+1;
			x= min(x,Max);
			y= random(5)+1;
			printf(" %d %d",x, y);
			for (j= 2;j<=k;j++){
				x= x+random(3)+1;
				y= random(5)+1;
				printf(" %d %d",x, y);
			}
			printf("\n");
		}
	}printf("0 0");
	return 0;
}
