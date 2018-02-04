#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int sig= 1e9,maxn= 300001,sig2= 1e9;
int par[maxn];
int n,m,i;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	n= 10000;m= 1e9;
	printf("%d %d\n",n, m);
	for (i= 2;i<=n;i++)
		par[i]= i-1;
	for (i= 1;i<=n;i++){
		int x= random(n-1)+2;
		par[x]= random(par[x])+1;
	}
	for (i= 1;i<=n;i++)
		printf("%d %d %d\n",par[i],random(sig)+1,random(sig2)+1);
	return 0;
}
