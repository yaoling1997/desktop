#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
ll a,b,n,ans;
void gcd(ll a,ll b,ll &x,ll &y){
	if (!b){x= 1;y= 0;return;}
	gcd(b,a%b,x,y);
	ll t= x;
	x= y;
	y= t-a/b*y;
}
ll ksm(ll a,ll b,ll mo){
	ll t= 1;
	while (b){
		if (b&1) t= t*a%mo;
		b>>= 1;a= a*a%mo;
	}return t;
}
ll logMod(ll a,ll b,ll n){
	ll v,m,i,e= 1,y;
	map<ll,ll> X;
	m= sqrt(n+0.5);
	gcd(ksm(a,m,n),n,v,y);
	X[1]= 0;
	for (i= 1;i<m;i++){
		e= e*a%n;
		if (!X.count(e)) X[e]= i;
	}
	for (i= 0;i<m;i++){
		if (X.count(b)) return i*m+X[b];
		b= b*v%n;
	}return -1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld %lld %lld",&a, &b, &n);
	ans= logMod(a,b,n);
	printf("%lld",(ans+n)%n);
	return 0;
}
