#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn= 3001,sig= 5;
int n,m,k,i,x,y;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= random(3)+50;m= n+5;k= random(2)+1;
	printf("%d %d %d\n",n, m, k);
	for (i= 1;i<=n;i++)
		printf("%d %d %d\n",i,i-1,random(sig));
	for (i= n+1;i<=m;i++){
		do x= random(n+1),y= random(n+1);
		while (x==y);
		printf("%d %d %d\n",x,y,random(sig));
	}
	return 0;
}
