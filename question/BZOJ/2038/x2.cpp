#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn= 30001;
ll a[maxn],b[maxn],c[maxn];
ll n,m,i,j,ans,sum,x,y,z;
ll gcd(ll a,ll b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%lld %lld",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%lld",&a[i]);
		c[i]= i*(i-1)/2;
	}
	for (ll a1= 1;a1<=m;a1++){
		scanf("%lld %lld",&x, &y);
		memset(b,0,sizeof(b));
		sum= 0;
		for (i= x;i<=y;i++)
			b[a[i]]++;
		for (i= 1;i<=n;i++)
			sum+= c[b[i]];
		z= c[y-x+1];
		x= gcd(sum,z);
		printf("%lld/%lld\n",sum/x,z/x);
	}
	return 0;
}
