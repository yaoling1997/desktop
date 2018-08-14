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
ll l,r,now,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d",&l, &r);
	now=1;
	while (now<=r){
		ll tmp=now;
		while (tmp<=r){
			if (tmp>=l)
				ans++;
			tmp*=3;
		}
		now*=2;
	}
	printf("%I64d",ans);
	return 0;
}
