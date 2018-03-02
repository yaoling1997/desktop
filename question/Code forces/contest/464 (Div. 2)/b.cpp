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
ll a[maxn];
ll n,k,x,y;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d",&n, &k);
	for (int i=1;i<=k;i++){
		scanf("%I64d",a+i);
		if (!x||a[x]*y<a[i]*(n/a[i])){
			x=i;
			y=n/a[i];
		}
	}
	printf("%I64d %I64d",x,y);
	return 0;
}
