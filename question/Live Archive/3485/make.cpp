#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int sig= 10;
int D,H,B,L,T;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	T= random(4)+2;
	printf("%d\n",T);
	for (int a1= 1;a1<=T;a1++){
		L= random(sig)+2;B= random(L)+1;
		H= random(sig)+1;D= random(sig)+1;
		printf("%d %d %d %d\n",D, H, B, L);
	}return 0;
}
