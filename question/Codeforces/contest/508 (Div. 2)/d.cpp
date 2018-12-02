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
int a[maxn];
int n,cnt;
ll ans;
ll solve(){
	if (n==1)
		return a[1];
	ll re=0;
	if (cnt==0){
		int p=0;
		for (int i=1;i<=n;i++){
			if (!p||a[p]<a[i])
				p=i;
			re-=a[i];
		}
		re+=2*a[p];
	}else if (cnt!=n){
		for (int i=1;i<=n;i++)
			re+=abs(a[i]);
	}else {
		int p=0;
		for (int i=1;i<=n;i++){
			if (!p||a[p]>a[i])
				p=i;
			re+=a[i];
		}
		re-=2*a[p];
	}
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
		if (a[i]>=0)
			cnt++;
	}
	ans= solve();
	printf("%I64d",ans);
	return 0;
}
