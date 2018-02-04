#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int sig= 100;
int n,m,i,j,x,y;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 600+random(3);m= random(10)+2000;
	printf("%d %d\n",n,m);
	for (i= 1;i<n;i++)
		printf("%d ",random(sig)-sig/2);
	printf("%d\n",random(sig)-sig/2);
	for (i= 1;i<m;i++){
		x= random(6)+1;if (n==1) x= 3;
		if (x==1){
			printf("INSERT ");
			x= random(n+1);y= random(sig)+1;
			printf("%d %d ",x,y);n+= y;
			for (j= 1;j<y;j++)
				printf("%d ",random(sig)-sig/2);
			if (y!=0)
				printf("%d",random(sig)-sig/2);
			printf("\n");
		}else if (x==2){
			x= random(n)+1;y= random(n-x+1);if (!y && n) y= 1;
			printf("DELETE %d %d\n",x,y);n-= y;
		}else if (x==3){
			x= random(n)+1;y= random(n-x+1);
			printf("MAKE-SAME %d %d %d\n",x,y,random(sig)-sig/2);
		}
		else if (x==4){
			x= random(n)+1;y= random(n-x+1);if (!y && n) y= 1;
			printf("REVERSE %d %d\n",x,y);
		}
		else if (x==5){
			x= random(n)+1;y= random(n-x+1);if (!y && n) y= 1;
			printf("GET-SUM %d %d\n",x,y);
		}else {
			printf("MAX-SUM\n");
		}
	}
	printf("MAX-SUM\n");
	return 0;
}
