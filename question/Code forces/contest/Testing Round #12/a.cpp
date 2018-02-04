#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
ll a,b,ans,k,x1,x2,x3,x4;
ll get(ll a){
	return a/k+1;
}
int main()
{
	scanf("%lld%lld%lld",&k, &a, &b);
	x1= get(max(abs(a)-1,0ll));
	x2= get(abs(a));
	x3= get(max(abs(b)-1,0ll));
	x4= get(abs(b));
	if (a>0) ans= x4-x1;
	else if (b>=0) ans= x4+x2-1;
	else ans= x2-x3;
	printf("%lld",ans);
	return 0;
}
