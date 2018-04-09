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
ll n,ans,b;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d",&n);
	b=1;
	while (n>1){
		ans+=n/2*b;
		b*=2;
		n-=n/2;
	}
	printf("%I64d",ans);
	return 0;
}
