#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
const ll maxn= 2e5;
ll c[20][maxn],f[20][maxn],a[maxn];
ll n,k,i,j,cnt,ans;
ll lowbit(ll o){
	return o & (-o);
}
void add(ll k,ll o,ll x){
	while (o<=n){
		c[k][o]+= x;
		o+= lowbit(o);
	}
}
ll find(ll k,ll o){
	ll re= 0;
	while (o){
		re+= c[k][o];
		o-= lowbit(o);
	}return re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld%lld",&n, &k);
	k++;
	for (i= 1;i<=n;i++)
		scanf("%lld",&a[i]);
	add(0,1,1);
	for (i= 1;i<=n;i++){
		for (j= k;j>=1;j--){
			f[j][i]= find(j-1,a[i]);
			add(j,a[i],f[j][i]);
		}
		ans+= f[k][i];
	}
	printf("%lld",ans);
	return 0;
}
