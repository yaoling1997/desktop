#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
ll x,y;
ll gcd(ll a,ll b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%lld%lld",&x, &y);
	if (gcd(x,y)!=1){
		printf("Impossible\n");
		return 0;
	}
	while (x&&y){
		if (x>y){
			printf("%lld%c",(x-1)/y,'A');
			x%= y;
		}else {
			printf("%lld%c",(y-1)/x,'B');
			y%= x;
		}
	}return 0;
}
