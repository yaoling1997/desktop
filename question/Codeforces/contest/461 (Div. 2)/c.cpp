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
ll n,k;
bool solve(){
	n++;
	for (ll i=1;i<=k;i++)
		if (n%i!=0)
			return false;
	return true;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d",&n, &k);
	printf("%s",solve()?"Yes":"No");
	return 0;
}
