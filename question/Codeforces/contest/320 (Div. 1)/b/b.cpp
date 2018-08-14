#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll M= 2e18;
const ll maxn= 2e5+10;
ll a[maxn],b[1000];
ll n,k,x,i,X,ans;
void change(ll x,ll y){
	ll i= 0;
	while (x){
		if (x&1) b[i]+= y;
		x>>= 1;
		i++;
	}
}
void update(){
	ll i= 0,p= 1,re= 0;
	while (p<=M){
		if (b[i]) re+= p;
		i++;
		p*= 2;
	}
	ans= max(ans,re);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%I64d%I64d%I64d",&n, &k, &x);
	X= 1;
	for (i= 1;i<=k;i++)
		X*= x;
	for (i= 1;i<=n;i++){
		scanf("%I64d",&a[i]);
		change(a[i],1);
	}
	for (i= 1;i<=n;i++){
		change(a[i],-1);
		change(a[i]*X,1);
		update();
		change(a[i]*X,-1);
		change(a[i],1);
	}
	printf("%I64d",ans);
	return 0;
}
