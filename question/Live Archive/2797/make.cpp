#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int n,m,i,j,x,y,z,T;
int random(int o){
	return rand()%o;
}
int R(int l,int r){
	return random(r-l+1)+l;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(3)+10;
	while (T--){
		n= random(6)+1;
		printf("%d\n",n);
		for (i= 1;i<=n;i++)
			for (j= 1;j<=4;j++)
				printf("%d%c",R(-5,5),j<4?' ':'\n');
	}printf("0");
	return 0;
}
