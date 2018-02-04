#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn= 100;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	int l= random(500)+1,a,b,c;
	a= random(maxn)+1;
	b= random(maxn)+1;
	c= random(maxn)+1;
	printf("%d %d %d %d",l, a, b, c);
	return 0;
}
