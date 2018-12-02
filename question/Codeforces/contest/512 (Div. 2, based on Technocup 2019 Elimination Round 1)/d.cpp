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
ll n,m,k;
ll gcd(ll a,ll b){
	if (!b)
		return a;
	return gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d%I64d",&n, &m, &k);
	if (2*n*m%k==0){
		ll x,y,g;
		g=gcd(k,n);
		x=n/g;
		y=2*n*m/k/x;
		if (y>m){
			y/=2;
			x*=2;
		}
		printf("YES\n");
		printf("%d %d\n",0,0);
		printf("%I64d %d\n",x,0);
		printf("%d %I64d\n",0,y);
	}else {
		printf("NO");
	}return 0;
}
