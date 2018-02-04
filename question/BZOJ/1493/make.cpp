#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 10;
int n,c,q,i,x;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 50000;c= 30;
	printf("%d %d\n",n, c);
	for (i= 1;i<=n;i++)
		printf("%d%c",random(c)+1,i<n?' ':'\n');
	q= 50000;
	printf("%d\n",q);
	for (i= 1;i<=q;i++){
		x= random(6)+1;
		x= 4;
		if (i==q) x= 5;
		if (x==1){
			printf("R %d",random(n-1)+1);
		}else if (x==2){
			printf("F");
		}else if (x==3){
			printf("S %d %d",random(n)+1,random(n)+1);
		}else if (x==4){
			printf("P %d %d %d",random(n)+1,random(n)+1,random(c)+1);
			//printf("P %d %d %d",1,n,random(c)+1);			
		}else if (x==5){
			printf("C");
		}else {
			printf("CS %d %d",random(n)+1,random(n)+1);
		}printf("\n");
	}return 0;
}
