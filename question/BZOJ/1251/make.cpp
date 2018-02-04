#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int random(int o){return rand()%o;}
int n,m,i,x;
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 800;m= 1000;
	printf("%d %d\n",n, m);
	for (i= 1;i<=m;i++){
		x= random(2)+1;
		if (x==2) x= 3;
		printf("%d ",x);
		int l= random(n)+1,r= random(n-l+1)+l;
		if (x==1){
			printf("%d %d %d\n",l, r, random(30)-10);
		}else printf("%d %d\n",l, r);
	}
	return 0;
}
