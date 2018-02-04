#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int mm[4]={2,3,4679,35617};
const int maxn= 40001,mo= 999911659;
ll c[4][maxn],a[4],stack[1000000],b[maxn],d[maxn];
ll ans,n,g,squ,i,j,top,tot,m;
void gcd(ll a,ll b,ll &x,ll &y){
	if (!b){x= 1;y=0;return;}
	gcd(b,a%b,x,y);
	ll t= x;
	x= y;
	y= t-a/b*y;
}
ll lucas(ll m,ll n,ll o){
	ll re= 1,x,y,p= mm[o];
	while(n || m){
		if (n%p>m%p) return 0;
		re= re*c[o][m%p]%p;
		gcd(c[o][m%p-n%p],p,x,y);
		re= re*x%p;
		gcd(c[o][n%p],p,x,y);
		re= re*x%p;
		n/= p;m/= p;
	}return re;
}
ll china(ll *a,ll M){
	int i;ll x= 0;
	for (i= 0;i<=3;i++){
		ll w= M/mm[i],p,q;
		gcd(w,mm[i],p,q);
		x= (x+w*p*a[i])%M;
	}
	return (x+M)%M;
}
ll count(ll n){
	ll re;
	int i,j;
	for (j= 0;j<=3;j++)
		for (i= 1;i<=top;i++)
			a[j]= (a[j]+lucas(n,n/stack[i],j))%mm[j];	
	re= china(a,mo-1);
	return re;
}
ll ksm(ll a,ll b,ll mo){
	ll t= 1;
	while (b){
		if (b&1) t= t*a%mo;
		b>>= 1;a= a*a%mo;
	}
	return t;
}
void init(int o,int s){
	if (o>tot){
		stack[++top]= s;
		return;
	}
	init(o+1,s);
	for (int i= 1;i<=b[o];i++){
		s*= d[o];
		init(o+1,s);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld %lld",&n, &g);
	if (g%mo==0){printf("0");return 0;}
	m= n;
	for (i= 2;i<=sqrt(m);i++)
		if (m%i==0){
			d[++tot]= i;
			while (m%i==0)
				m/= i,b[tot]++;
			if (m==1) break;
		}
	if (m!=1) d[++tot]= m,b[tot]++;
	init(1,1);
	for (j= 0;j<=3;j++){
		c[j][0]= 1;
		for (i= 1;i<=35617;i++)
			c[j][i]= c[j][i-1]*i%mm[j];
	}
	squ= count(n);
	ans= ksm(g,squ,mo);
	printf("%lld",ans);
	return 0;
}
