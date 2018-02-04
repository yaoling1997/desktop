#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn= 300000;
ll f[maxn];
ll ans;
int n,m,i,j;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	if (n<m) swap(n,m);
	for (i= m;i>=1;i--){
		f[i]= (ll)(n/i)*(m/i);
		for (j= 2;j<=m/i;j++)
			f[i]-= f[j*i];
		ans+= f[i]*(2*i-1);
	}printf("%lld\n",ans);
	return 0;
}
