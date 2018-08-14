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
ll n,l,r,ans;
ll Range(ll x){
	if (x<=1) return 1;
	return 2*Range(x/2)+1;
}
ll get(ll x,ll l,ll r){
	if (x==0) return 0;
	if (x==1) return l<=1&&1<=r;
	ll R= Range(x/2);
	ll re= 0;
	if (l<R+1)
		re+= get(x/2,l,r);
	if (r>R+1)
		re+= get(x/2,l-R-1,r-R-1);
	if (l<=R+1&&R+1<=r)
		if (x%2)
			re++;
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d%I64d",&n, &l, &r);
	ans= get(n,l,r);
	printf("%I64d",ans);
	return 0;
}