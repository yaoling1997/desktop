#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 3001,sig= 2;
char st[maxn];
int T,n,i,len,j,top;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(2)+1;
	for (i= 1;i<=2;i++)
		st[++top]= i+96;
	st[++top]= '*';
	printf("%d\n",T);
	for (int a1= 1;a1<=T;a1++){
		n= random(1)+2;
		printf("%d\n",n);
		for (i= 1;i<=n;i++){
			len= random(4)+1;
			for (j= 1;j<=len;j++)
				printf("%c",st[random(top)+1]);
			printf("\n");
		}
	}return 0;
}
