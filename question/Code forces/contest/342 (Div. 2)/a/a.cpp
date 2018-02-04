#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
ll a,b,c,n,ans;
void getb(ll &x){
	if (x<b) return;
	ll k= (x-b)/(b-c)+1;
	ans+= k;
	x-= k*(b-c);
}
void geta(ll &x){
	if (x<a) return;
	ll k= x/a;
	ans+= k;
	x-= k*a;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n, &a, &b, &c);
	if (a>=b){
		getb(n);
	}else if (a>b-c){
		getb(n);
		geta(n);
	}else geta(n);
	printf("%lld",ans);
}
