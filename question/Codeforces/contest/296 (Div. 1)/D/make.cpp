#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<ctime>
#include<sys/timeb.h>
using namespace std;
char c[4];
int S,T,K,i;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.millitm+t.time*1000);
	S= random(20)+2;T= random(S)+1;K= random(S);
	c[0]= 'A';c[1]= 'T';c[2]= 'G';c[3]= 'C';
	printf("%d %d %d\n",S, T, K);
	for (i= 1;i<=S;i++)
		printf("%c",c[random(4)]);printf("\n");
	for (i= 1;i<=T;i++)
		printf("%c",c[random(4)]);printf("\n");
	return 0;
}
