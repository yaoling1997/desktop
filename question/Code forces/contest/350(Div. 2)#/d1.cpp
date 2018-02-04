#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 2e5;
ll a[maxn],b[maxn];
ll n,K,l,r,i,j,ans;
bool ok(ll m){
	ll i,re= 0;
	for (i= 1;i<=n;i++)
		if (b[i]<a[i]*m)
			re+= a[i]*m-b[i];
	return K>=re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d",&n, &K);
	for (i= 1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for (i= 1;i<=n;i++)
		scanf("%I64d",&b[i]);
	l= 0,r= 10000;
	while (l+1<r){
		ll m= (l+r)>>1;
		if (ok(m)) l= m;
		else r= m;
	}printf("%I64d",l);
	return 0;
}