#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<sys/timeb.h>
#define ll long long
using namespace std;
int i,j,k,M;
int random(int o){
	return rand()%o;
}	
void put(int M){
	int i;
	printf("%d",random(9)+1);
	for (i= 2;i<=M;i++)
		printf("%d",random(10));
	printf(" ");
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	M= 1;
	put(M);
	put(random(M)+1);
	put(random(M)+1);
	return 0;
}
