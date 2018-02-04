#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int sig= 1e9;
int n,m,i,x,l,r,k;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	n= 10000;m= 10000;
	printf("%d %d\n",n, m);
	for (i= 1;i<n;i++)
		printf("%d ",random(sig)-sig/2);
	printf("%d\n",random(sig));
	for (i= 1;i<=m;i++){
		x= random(1)+1;
		if (x){
			printf("Q ");
			r= random(n)+1;l= random(r)+1;
			printf("%d %d %d\n",l, r, random(r-l+1)+1);
		}else {
			printf("C ");
			l= random(n)+1;k= random(sig);
			printf("%d %d\n",l, k-sig/2);
		}
	}
	return 0;
}
