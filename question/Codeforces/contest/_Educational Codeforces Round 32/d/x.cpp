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
ll f[10];
ll n,k;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d",&n, &k);
	f[1]= 1;
	f[2]=n*(n-1)/2+f[1];
	f[3]=n*(n-1)*(n-2)/2/3*2+f[2];
	f[4]=n*(n-1)*(n-2)*(n-3)/2/3/4*9+f[3];
	printf("%I64d",f[k]);
	return 0;
}
