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
ll n;
int count(ll x){
	int re=0;
	while (x){
		re+=x%10;
		x/=10;
	}
	return re;
}
int solve(ll n){
	ll x=0;
	while (x*10+9<=n){
		x=x*10+9;
	}
	ll y=n-x;
	return count(x)+count(y);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d",&n);
	int ans;
	ans=solve(n);
	printf("%d",ans);
	return 0;
}
