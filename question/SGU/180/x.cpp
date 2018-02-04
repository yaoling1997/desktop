#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 7e4;
struct node{
	ll v,h;
}a[maxn];
ll c[maxn];
ll n,i,x,cnt,now,tot,ans;
bool cmpv(node a,node b){
	return a.v<b.v;
}
bool cmph(node a,node b){
	return a.h<b.h;
}
ll lowbit(ll o){
	return o&(-o);
}
ll find(ll o){
	ll re= 0;
	while (o>0){
		re+= c[o];
		o-= lowbit(o);
	}return re;
}
void add(ll o,ll x){
	while (o<=n){
		c[o]+= x;
		o+= lowbit(o);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld",&a[i].v);
		a[i].h= i;
	}
	sort(a+1,a+n+1,cmpv);
	now= a[1].v;
	a[1].v= ++tot;
	for (i= 2;i<=n;i++)
		if (a[i].v==now)
			a[i].v= tot;
		else {
			now= a[i].v;
			a[i].v= ++tot;
		}
	sort(a+1,a+n+1,cmph);
	for (i= 1;i<=n;i++){
		ans+= i-1-find(a[i].v);
		add(a[i].v,1);
	}
	printf("%lld",ans);
	return 0;
}
