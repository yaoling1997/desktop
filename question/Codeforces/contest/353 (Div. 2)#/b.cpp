#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e5;
ll cnt,n,a,b,c,d,i;
bool ok(ll x){
	return x>=1&&x<=n;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d%I64d%I64d%I64d",&n, &a, &b, &c, &d);
	for (i= 1;i<=n;i++)
		if (ok(i+b-c)&&ok(i+a-d)&&ok(i+a+b-c-d))
			cnt++;
	printf("%I64d",cnt*n);
	return 0;
}
