#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int i,w,n,m,j;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	w= random(10)+1;
	printf("%d\n",w);
	for (i= 1;i<=w;i++){
		n= random(100)+1;m= random(1000)+1;
		printf("%d %d\n",n,m);
		for (j= 1;j<=m;j++){
			int r= random(n)+1,l= random(r)+1;
			printf("%d %d %d\n",l, r, random(1000)+1);
		}
	}
}
