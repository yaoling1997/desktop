#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
#define ll long long
const int maxn= 3001;
using namespace std;
int T,n,m,i;
ll random(ll o){
	return (ll)rand()*rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(5)+2;
	while (T--){
		//n= random(5000)+1;m= random(10000)+1;
		n= random(1e3)+1;m= random(1e3)+1;		
		//n= 1e5;m= 1e5;
		for (i= 1;i<=n;i++)
			printf("%c",(int)random(3)+'a');
		printf("\n");
		printf("%d\n",m);
		for (i= 1;i<=m;i++)
			printf("%lld\n",random(1e3)+1);
	}return 0;
}
