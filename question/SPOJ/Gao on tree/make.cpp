#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
int T,n,m,i,s;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= 1;
	while (T--){
		n= 1e5;m= 2e5;
		//n= random(70000)+30000;m= random(170000)+30000;
		s= random(n)+1;
		//n= 3;m= 3;		
		printf("%d %d\n",n, m);
		for (i= 1;i<=n;i++)
			printf("%d%c",random(n)+1,i<n?' ':'\n');
		for (i= 2;i<=n;i++)
			printf("%d %d\n",i,random(i-1)+1);
		for (i= 1;i<=m;i++)
			printf("%d %d %d\n",random(n)+1,random(n)+1,random(s)+1);
	}
	return 0;
}
