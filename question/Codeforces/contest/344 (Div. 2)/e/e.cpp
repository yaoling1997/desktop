#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-8;
const ll maxn= 3e5;
double k[maxn],b[maxn],X[maxn];
ll a[maxn],s[maxn];
ll o,ans,data;
ll n,i,j,x,y,cl,cp;
ll getr(ll x){
	if (!cp) return floor(k[1]*x+b[1]+eps);
	ll l= 0,r= cp+1;
	while (l+1<r){
		ll mid= (l+r)>>1;
		if (x>=X[mid]) l= mid;
		else r= mid;
	}
	return floor(k[l+1]*x+b[l+1]+eps);
}
ll getl(ll x){
	if (!cp) return floor(k[1]*x+b[1]+eps);
	ll l= 0,r= cp+1;
	while (l+1<r){
		ll mid= (l+r)>>1;
		if (x<=X[mid]) l= mid;
		else r= mid;
	}
	return floor(k[l+1]*x+b[l+1]+eps);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]= a[i]+s[i-1];
		o+= i*a[i];
	}
	ans= o;
	///////////right///////////////
	for (i= 1;i<=n;i++){
		cl++;
		k[cl]= i;
		b[cl]= -s[i-1];
		if (cl>1){
			cp++;
			X[cp]= (b[cl]-b[cl-1])/(k[cl-1]-k[cl]);
			while (cp>1&&X[cp]<=X[cp-1]){
				cl--;
				k[cl]= k[cl+1];
				b[cl]= b[cl+1];
				cp--;
				X[cp]= (b[cl]-b[cl-1])/(k[cl-1]-k[cl]);
			}
		}
		data= getr(a[i])+s[i-1]-i*a[i];
		if (ans<o+data)
			ans= o+data;
	}
	////////////left/////////////////
	cl= cp= 0;
	for (i= n;i>0;i--){
		cl++;
		k[cl]= i;
		b[cl]= -s[i];
		if (cl>1){
			cp++;
			X[cp]= (b[cl]-b[cl-1])/(k[cl-1]-k[cl]);
			while (cp>1&&X[cp]>=X[cp-1]){
				cl--;
				k[cl]= k[cl+1];
				b[cl]= b[cl+1];
				cp--;
				X[cp]= (b[cl]-b[cl-1])/(k[cl-1]-k[cl]);
			}
		}
		data= getl(a[i])+s[i]-i*a[i];
		if (ans<o+data)
			ans= o+data;
	}
	printf("%lld",ans);
	return 0;
}
