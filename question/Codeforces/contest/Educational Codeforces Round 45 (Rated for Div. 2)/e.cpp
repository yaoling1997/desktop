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
const int maxn= 1e6+10;
int b[maxn],a[maxn],p[maxn],f[maxn];
int n,m,k,la;
ll ans;
ll check(int o){
	ll re=0;
	int now=0;
	while (now<n){
		int pre=now;
		now=now+p[o];
		re+=a[o];
		if (now<n&&b[now])
			now=f[now];
		if (now==pre)
			return -1;
	}
	return re;
}
void solve(){
	if (check(la)==-1){
		ans=-1;
		return;
	}
	ans= check(la);
	for (int i=1;i<la;i++){
		ll re= check(i);
		if (re!=-1&&re<ans)
			ans=re;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &m, &k);
	for (int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		b[x]=1;
	}
	if (b[0]){
		printf("-1");
		return 0;
	}
	for (int i=0;i<n;i++){
		f[i]=i;
		if (b[i])
			f[i]=f[i-1];
	}
	for (int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		while (la&&a[la]>=x){
			la--;
		}
		a[++la]=x;
		p[la]=i;
	}
	solve();
	printf("%I64d",ans);
	return 0;
}
