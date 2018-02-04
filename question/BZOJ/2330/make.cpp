#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int x,y,z,i,n,m;
int random(int o){return rand()%o;}
int main()
{
	srand(time(NULL));
	freopen("1.in","w",stdout);
	n= 4;m= random(6)+1;
	printf("%d %d\n",n,m);
	for (i= 1;i<=m;i++){
		x= random(5)+1;
		do y= random(n)+1,z= random(n)+1;
		while (y==z);
		printf("%d %d %d\n",x, y, z);
	}
	return 0;
}
