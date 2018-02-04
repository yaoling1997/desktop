#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/timeb.h>
using namespace std;
const int maxn= 300,sig= 2;
char ch[5],ch1[5];
int n,m,k,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 2;m= 2;ch[0]= 'E';ch[1]= 'W';ch1[0]= 'N';ch1[1]= 'S';
	printf("%d %d\n",m, n);
	for (i= 1;i<=m;i++)
		printf("%c",ch[random(2)]);printf("\n");
	for (i= 1;i<=n;i++)
		printf("%c",ch1[random(2)]);printf("\n");
	for (i= 1;i<=m;i++)
		printf("%d%c",random(sig)+1,i<m?' ':'\n');
	for (i= 1;i<=n;i++)
		printf("%d%c",random(sig)+1,i<n?' ':'\n');
	k= 2;
	printf("%d\n",k);
	for (i= 1;i<=k;i++){
		printf("%d %d %d %d\n",random(m)+1,random(n)+1,random(m)+1,random(n)+1);
	}return 0;
}
