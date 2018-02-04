#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int sig= 9;
int i,n,m,x,l,r,g;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 100;m= 50;
	printf("%d %d\n",n, m);
	for (i= 1;i<=n;i++)
		printf("%d ",random(sig));
	printf("\n");
	for (i= 1;i<=m;i++){
		x= random(3)+1;r= random(n)+1;l= random(r)+1;
		printf("%d ",x);
		if (x==1) {
			printf("%d %d %d\n",l, r, random(sig));
		}else if (x==2){
			printf("%d %d %d\n",l, r,random(r-l+1)+1);
		}else if (x==3){
			printf("%d %d\n",l, random(sig));
		}else if (x>=4){
			printf("%d %d %d\n",l, r, random(sig));
		}
	}
	return 0;
}
