#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 3e5;
ll a[maxn],s[maxn];
ld x,y,ans;
ll n,i,j,I,M,l,r;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (i= 1;i<=n;i++)
		s[i]= s[i-1]+a[i];
	I= 1,M= 0;
	for (i= 2;i<n;i++){
		l= 0,r= min(i-1,n-i)+1;
		while (l+1<r){
			ll m= (l+r)>>1,j= m-1;
			x= ((ld)s[i]-s[i-m-1]+s[n]-s[n-m])/(2*m+1);
			y= ((ld)s[i]-s[i-j-1]+s[n]-s[n-j])/(2*j+1);
			if (x>y) l= m;
			else r= m;
		}
		x= ((ld)s[i]-s[i-l-1]+s[n]-s[n-l])/(2*l+1);
		if (x-a[i]>ans){
			ans= x-a[i];
			I= i;
			M= l;
		}
	}printf("%lld\n",2*M+1);
	for (i= I-M;i<=I;i++)
		printf("%lld ",a[i]);
	for (i= n-M+1;i<=n;i++)
		printf("%lld ",a[i]);
}
