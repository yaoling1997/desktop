#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int i,r,l;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	for (i= 1;i<=100;i++){
		r= random(2*1e9)+1;l= random(r)+1;
		printf("%d %d\n",l, r);
	}
	return 0;
}
