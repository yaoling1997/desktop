#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 1000;
ll f[maxn];
ll N,P,k;
ll dfs(ll o){
	if (f[o]!=-1) return f[o];
	f[o]= 0;
	if (o%2);
	else {
		ll i;
		for (i= 0;i<=o-2;i++)
			f[o]+= dfs(i)*dfs(o-2-i);
	}return f[o];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld",&k);
	P= k+1;
	memset(f,-1,sizeof(f));
	f[0]= 1;
	N= dfs(2*k);
	printf("%lld %lld\n",N, P);
	return 0;
}
