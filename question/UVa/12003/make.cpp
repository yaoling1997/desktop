#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int sig= 1e9;
int random(int o){return rand()%o;}
int l,r,v,p,n,m,i,u;
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 300000;m= 50000;u= random(100000)+1;
	printf("%d %d %d\n",n, m, u);
	for (i= 1;i<=n;i++) printf("%d\n",random(sig));
	for (i= 1;i<=m;i++){
		r= n;l= 1;v= random(sig)+1;p= random(n)+1;
		printf("%d %d %d %d\n",l, r, v, p);
	}
	return 0;
}
