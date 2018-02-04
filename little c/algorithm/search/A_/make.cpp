#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int i,j,x,y,n,m;
int random(int o){return rand()%o;}
int main(){
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 3000;m= 3000;x= 1;y= 1;
	printf("%d %d %d %d\n",n, m, x, y);
	printf("0");
	for (i= 1;i<=n;i++){
		if (i==1) x= 2;else x= 1;
		for (j= x;j<m;j++){
			y= random(2); y= 0;
			if (y)
				printf("%d",random(2));
			else printf("0");
		}
		if (i<n) printf("0\n");
		else printf("2\n");
	}
	return 0;
}
		 
