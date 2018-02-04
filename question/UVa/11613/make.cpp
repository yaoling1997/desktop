#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,X= 30;
int T,i,M,I;
int R(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= R(X)+1;
	printf("%d\n",T);
	while (T--){
		M= R(X)+1;I= R(X);
		printf("%d %d\n",M, I);
		for (i= 1;i<=M;i++)
			printf("%d %d %d %d %d\n",R(X),R(X),R(X),R(X),R(X));		
	}return 0;
}
