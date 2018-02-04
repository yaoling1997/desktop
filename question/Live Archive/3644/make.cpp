#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int M= 5;
int T,i,x,y,n;
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
		n= random(3)+1;
		while (n--){
			do x= random(M),y= random(M);
			while (x==y);
			printf("%d %d\n",x,y);
		}
		printf("-1\n");
	}return 0;
}
