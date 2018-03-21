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
ll n,q,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d",&n, &q);
	while (q--){
		ll x;
		scanf("%I64d",&x);
		while (x%2==0){
			x=x+(n-x/2);
		}
		ans=(x+1)/2;
		printf("%I64d\n",ans);
	}
	return 0;
}
