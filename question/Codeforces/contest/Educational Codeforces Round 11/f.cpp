#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 5e5;
ll a[maxn],s[maxn],p[maxn];
ld X[maxn],Y[maxn];
ll i,j,n,ans,la,x,y;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d",&n);
	for (i= 1;i<=n;i++){
		scanf("%I64d",&a[i]);
		s[i]= s[i-1]+a[i];
		p[i]= p[i-1]+a[i]*i;
	}
	la= 1;
	X[1]= Y[1]= 0;
	for (i= 1;i<=n;i++){
		ll l= 1,r= la+1;
		while (l+1<r){
			ll m= (l+r)>>1;
			ld k= (Y[m]-Y[m-1])/(X[m]-X[m-1]);
			if (k>=s[i]) l= m;
			else r= m;
		}
		ans= max((ld)ans,Y[l]+p[i]-X[l]*s[i]);
		ld tx,ty;
		tx= i;ty= -p[i]+i*s[i];
		while (la>1&&(ty-Y[la])/(tx-X[la])>(Y[la]-Y[la-1])/(X[la]-X[la-1])) la--;
		la++;
		X[la]= tx;
		Y[la]= ty;
	}printf("%I64d",ans);
	return 0;
}
