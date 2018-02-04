#include<cstdio>
#include<cstdlib>
#include<sys/timeb.h>
#define ll long long
using namespace std;
const ll sig= 10;
ll n,g;
ll random(ll o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(sig)+1;g= random(sig);
	//n= sig;g= sig;
	printf("%lld %lld",n,g);
	return 0;
}
