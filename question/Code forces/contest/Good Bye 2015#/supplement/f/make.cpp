#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 5e5;
char ch[10];
int n,h,w,i,j;
int R(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= R(15)+1;
	h= R(10000)+1;
	w= R(10000)+1;
	ch[0]= 'L';
	ch[1]= 'R';
	ch[2]= 'U';
	ch[3]= 'D';	
	printf("%d %d %d\n",n, h, w);
	for (i= 1;i<=n;i++)
		printf("%c",ch[R(4)]);
	return 0;
}
