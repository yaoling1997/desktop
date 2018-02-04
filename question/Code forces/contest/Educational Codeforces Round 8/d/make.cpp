#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<sys/timeb.h>
#define ll long long
using namespace std;
const int maxn= 3e3;
ll a[maxn],b[maxn];
ll x,y,m,d,n,i,bl;
ll R(ll o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	m= R(9)+1;d= R(10);
	printf("%lld %lld\n",m, d);
	n= R(20)+1;
	x= R(9)+1;y= R(x)+1;
	a[1]= y;
	b[1]= x;
	if (x>y) bl= 1;
	for (i= 2;i<=n;i++){
		if (bl){
			x= R(10);
			y= R(10);
		}else {
			x= R(9)+1;
			y= R(x)+1;
			if (x>y) bl= 1;
		}
		a[i]= y;
		b[i]= x;
	}
	for (i= 1;i<=n;i++)
		printf("%lld",a[i]);
	printf("\n");
	for (i= 1;i<=n;i++)
		printf("%lld",b[i]);
}
