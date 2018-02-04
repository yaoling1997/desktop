#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 3e5;
ll v[maxn],d[maxn],p[maxn],e[maxn];
ll ans[maxn];
ll n,i,j,x,y,z,lans,V,D;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld%lld%lld",&v[i], &d[i], &p[i]);
		e[i]= 1;
	}
	for (i= 1;i<=n;i++){
		if (!e[i]) continue;
		ans[++lans]= i;
		V= v[i];D= 0;
		for (j= i+1;j<=n;j++){
			p[j]-= V+D;
			if (!e[j]) continue;
			if (V>0) V--;
			if (p[j]<0){
				e[j]= 0;
				D+= d[j];
			}
		}
	}
	printf("%lld\n",lans);
	for (i= 1;i<=lans;i++)
		printf("%lld%c",ans[i], i<lans?' ':'\n');
	return 0;
}
