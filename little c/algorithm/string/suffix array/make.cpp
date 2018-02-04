#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int i,n,x,y,m;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= random(10)+60000;
	for (i= 1;i<=n;i++)
		printf("%c",random(2)+97);
	printf("\n");
	m= 10000;
	//	m= random(10)+100;
	printf("%d\n",m);
	for (i= 1;i<=m;i++){
		x= random(n)+1;y= random(n)+1;
		printf("%d %d\n",x,y);
	}
	return 0;
}	
