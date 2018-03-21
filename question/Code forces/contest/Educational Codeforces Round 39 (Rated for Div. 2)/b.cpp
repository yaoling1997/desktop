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
ll a,b;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d",&a, &b);
	for (;a!=0&&b!=0;){
		if (a>=2*b)
			a%=2*b;
		else if (b>=2*a)
			b%=2*a;
		else break;
	}
	printf("%I64d %I64d",a,b);
	return 0;
}
