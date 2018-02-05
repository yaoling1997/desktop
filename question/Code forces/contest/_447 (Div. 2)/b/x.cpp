#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
ll n,m,k,mo=1e9+7;
ll ksm(ll a,ll b){
	a%=mo;
	ll t= 1;
	while (b){
		if (b&1)
			t= t*a%mo;
		b>>= 1;
		a= a*a%mo;
	}
	return t;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d%I64d",&n, &m, &k);
	ll x=ksm(2,m-1);
	x= ksm(x,n-1);
	int ans= 0;
	if (k==1||(k==-1&&n%2==m%2))
		ans= x;
	printf("%d",ans);
	return 0;
}
