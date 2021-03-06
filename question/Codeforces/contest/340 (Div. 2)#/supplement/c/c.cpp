#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const ll oo= 5e18;
const ll maxn= 2e5;
ll X[maxn],Y[maxn];
ll x1,x2,y1,y2;
ll ans,r1f,r2f;
ll n,i,j;
ll dis(ll x1,ll y1,ll x2,ll y2){
	ll x= x2-x1,y= y2-y1;
	return x*x+y*y;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d",&n);
	scanf("%I64d%I64d%I64d%I64d",&x1, &y1, &x2, &y2);
	for (i= 1;i<=n;i++)
		scanf("%I64d%I64d",&X[i], &Y[i]);
	ans= oo;
	for (i= 1;i<=n;i++){
		r1f= dis(x1,y1,X[i],Y[i]);
		r2f= 0;
		for (j= 1;j<=n;j++){
			if (dis(x1,y1,X[j],Y[j])<=r1f) continue;
			r2f= max(r2f,dis(x2,y2,X[j],Y[j]));
		}
		ans= min(ans,r1f+r2f);
	}
	r2f= 0;
	for (i= 1;i<=n;i++)
		r2f= max(r2f,dis(x2,y2,X[i],Y[i]));
	ans= min(ans,r2f);
	printf("%I64d",ans);
}
