#include<cstdio>
#include<cstdlib>
#define ll long long
using namespace std;
ll a,b,c;
ll ksm(ll a,ll b,ll mo){
	ll t= 1;
	while (b){
		if (b & 1) t= t*a%mo;
		b>>= 1;a= a*a%mo;
	}
	return t;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld %lld %lld",&a, &b, &c);
	printf("%lld",ksm(a,b,c));
	return 0;
}
