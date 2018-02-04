#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
int n,i,x,M= 40,T;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(4)+1;
	while (T--){
		n= random(30)+1;
		printf("%d\n",n);
		for (i= 1;i<=n;i++){
			printf("%d %d %d\n",random(M)+1,random(M)+1,random(M)+1);
		}
	}
	return 0;
}
