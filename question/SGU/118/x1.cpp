#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 2e4;
struct bi{
	ll a[maxn];
	ll k;
	bi():k(1){}
	void mt(){
		ll i;
		for (i= 1;i<=k;i++){
			a[i+1]+= a[i]/10;
			a[i]%= 10;
		}
		while (a[k+1]){
			k++;
			a[k+1]= a[k]/10;
			a[k]%= 10;
		}
	}
	void clear(){
		memset(a,0,sizeof(a));
		k= 1;
	}
}ans,a;
ll A[maxn];
ll T,n,i,j,x,y;
void mul(bi &a,ll x){
	ll i;
	for (i= 1;i<=a.k;i++)
		a.a[i]*= x;
	a.mt();
}
void add(bi &a,bi &b){
	ll i;
	a.k= max(a.k,b.k);
	for (i= 1;i<=a.k;i++)
		a.a[i]+= b.a[i];
	a.mt();
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		scanf("%lld",&n);
		for (i= 1;i<=n;i++) scanf("%lld",&A[i]);
		ans.clear();
		a.clear();
		a.a[1]= 1;
		for (i= 1;i<=n;i++){
			mul(a,A[i]);
			add(ans,a);
		}
		x= 0;
		for (i= ans.k;i>0;i--)
			x+= ans.a[i];
		while (x>9){
			y= 0;
			while (x){
				y+= x%10;
				x/= 10;
			}
			x= y;
		}
		printf("%lld\n",x);
	}return 0;
}
