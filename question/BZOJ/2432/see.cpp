#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
const ll maxn= 3001;
ll f[maxn];
ll i,n,K;
int main()
{
	freopen("1.in","r",stdin);
	freopen("see.out","w",stdout);
	scanf("%lld %lld",&n, &K);
	f[1]= f[2]= 1;
	for (i= 3;i<=n;i++){
		f[i]= f[i-1]+f[i-2];
		if (f[i]%K==1) f[i]--;
	}for (i= 1;i<=n;i++)
		 printf("%lld ",f[i]);
	return 0;
}
