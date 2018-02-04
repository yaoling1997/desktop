#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn= 3001,sig= 300;
int n,par[maxn],i,j;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= random(500)+1;
	printf("%d\n",n);
	for (i= 2;i<=n;i++)
		par[i]= i-1;
	par[1]= 1;j= random(10)+1;
	for (i= 1;i<=j;i++){
		int x= random(n)+1;
		par[x]= random(par[x])+1;
	}
	for (i= 2;i<= n;i++)
		printf("%d %d\n",i,par[i]);
	for (i= 1;i<=n;i++)
		printf("%d ",random(2*sig)-sig);
	printf("\n");
	int q= random(100)+1;
	printf("%d\n",q);
	for (i= 1;i<=q;i++){
		int x= random(3);
		if (x==0){
			printf("QMAX %d %d\n",random(n)+1,random(n)+1);
		}else if (x==1)
			printf("QSUM %d %d\n",random(n)+1,random(n)+1);
		else {
			printf("CHANGE %d %d\n",random(n)+1,random(2*sig)-sig);
		}
	}
}
