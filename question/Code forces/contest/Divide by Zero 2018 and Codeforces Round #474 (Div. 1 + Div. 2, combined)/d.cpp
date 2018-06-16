#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
ll sta[100];
ll a[100],s[100],sum[100];
int Q,la;
int findLevel(ll X){
	ll cnt=0;
	for (int i=1;i<=60;i++){
		cnt+=s[i];
		if (X<=cnt)
			return i;
	}
	return 0;
}
void update(int o,ll X){
	a[o]=((a[o]+X)%s[o]+s[o])%s[o];
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	ll x=1;
	for (int i=1;i<=60;i++){
		s[i]=x;
		sum[i]=sum[i-1]+s[i];
		x*=2;
	}
	scanf("%d",&Q);
	for (int qq=1;qq<=Q;qq++){
		int T;
		ll X,K;
		scanf("%d",&T);
		if (T==1){
			scanf("%I64d%I64d",&X, &K);
			int re=findLevel(X);
			K%=s[re];
			update(re,K);
		}else if (T==2){
			scanf("%I64d%I64d",&X, &K);
			int re=findLevel(X);
			K%=s[re];
			for (int i=re;i<=60;i++){
				update(i,K);
				K*=2;
			}
		}else {
			la=0;
			scanf("%I64d",&X);
			int re=findLevel(X);
			ll id=X-sum[re-1]-1;
			id=(id+a[re])%s[re];
			while (re){
				sta[++la]=((id-a[re])%s[re]+s[re])%s[re]+sum[re-1]+1;
				id/=2;
				re--;
			}
			for (int i=1;i<=la;i++)
				printf("%I64d%c",sta[i],i<la?' ':'\n');
		}
	}
	return 0;
}
