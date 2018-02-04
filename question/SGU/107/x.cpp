#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll mo= 1e9,last= 987654321;
ll d[20],e[20];
ll i,j,ans,x,sum,n;
void dfs(ll o,ll now){
	if (o>=10){
		sum++;
		return;
	}
	ll i,x;
	for (i= 0;i<=9;i++){
		x= now+e[o-1]*i;
		if (x*x%e[o]==d[o]) dfs(o+1,x);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld",&n);
	x= 1;e[0]= 1;
	for (i= 1;i<=9;i++){
		d[i]= d[i-1]+x*i;
		x*= 10;
		e[i]= x;
	}
	if (n<=7){
		x= 1;
		for (i= 2;i<=n;i++)
			x*= 10;
		for (i= x;i<10*x;i++)
			if (i*i%mo==last) ans++;
		printf("%lld",ans);
	}else if (n==8){
		printf("0");
	}else {
		dfs(1,0);
		if (n==9) printf("%lld\n",sum);
		else {
			printf("%lld\n",sum*9);
			for (i= 1;i<=n-10;i++)
				printf("0");
		}
	}return 0;
}
