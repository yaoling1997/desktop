#include<cstdio>
#include<cstdlib>
#define ll long long
using namespace std;
int main()
{
	ll l,r,n,t,k;
	scanf("%I64d",&t);
	for (k= 1;k<=t;k++){
		scanf("%I64d %I64d %I64d",&n, &l, &r);
		ll k= n/l;
		if (n%l>(r-l)*k) printf("No\n");
		else printf("Yes\n");
	}
}
