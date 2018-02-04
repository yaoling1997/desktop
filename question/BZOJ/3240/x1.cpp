#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll maxl= 2e6,mo= 1e9+7,fmo= mo-1;
char s[maxl];
ll N[maxl],M[maxl];
ll t1,t2,a,b,c,d,i,x,y,z,A,B,C,D,ans;
void gcd(ll a,ll b){
	if (!b){
		x= 1;y= 0;
		return;
	}gcd(b,a%b);
	ll t= x;
	x= y;
	y= t-a/b*y;
}
ll ksm(ll a,ll b){
	ll t= 1;
	while (b){
		if (b&1) t= t*a%mo;
		b>>= 1;a= a*a%mo;
	}return t;
}
ll yu(ll *a,ll k,ll mo){
	ll p= 0,i;
	for (i= k;i>0;i--)
		p= (p*10+a[i])%mo;
	return p;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",s+1);
	t1= strlen(s+1);
	for (i= 1;i<=t1;i++)
		N[i]= s[t1-i+1]-'0';
	scanf("%s",s+1);
	t2= strlen(s+1);
	for (i= 1;i<=t2;i++)
		M[i]= s[t2-i+1]-'0';
	scanf("%lld %lld %lld %lld",&a, &b, &c, &d);
	M[1]--;i= 1;
	while (M[i]<0){
		M[i]+= 10;
		M[++i]--;
	}while (t2>1&&!M[t2]) t2--;
	z= yu(M,t2,fmo);
	if (a!=1){
		A= c*ksm(a,z)%mo;
		gcd(a-1,mo);
		B= (b*c%mo*(ksm(a,z)-1)%mo*x+d)%mo;
	}else {
		z= yu(M,t2,mo);		
		A= c;
		B= (b*c%mo*z+d)%mo;
	}
	z= yu(N,t1,fmo);
	A= (A+mo)%mo;
	if (A!=1){
		C= A;
		gcd(C-1,mo);
		D= B*x%mo;
		ans= ((1+D)*ksm(C,z)-D)%mo;
	}else {
		z= yu(N,t1,mo);
		ans= (1+z*B)%mo;
	}
	gcd(c,mo);	
	ans= ((ans-d)*x%mo+mo)%mo;
	printf("%lld\n",ans);
	return 0;
}
