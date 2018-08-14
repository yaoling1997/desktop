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
ll ST[maxn],ans[maxn],e[maxn];
ll V[maxn],T[maxn],c[maxn];
int n;
void solve(){
	for (int i=1;i<=n;i++){
		int p=lower_bound(ST+i,ST+n+1,ST[i-1]+V[i])-ST;
		c[i]++;
		c[p]--;
		V[i]-=ST[p-1]-ST[i-1];
		e[p]+=V[i];
	}
	for (int i=1;i<=n;i++){
		c[i]+=c[i-1];
		ans[i]=c[i]*T[i]+e[i];
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%I64d",&V[i]);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&T[i]);
		ST[i]=ST[i-1]+T[i];
	}
	solve();
	for (int i=1;i<=n;i++)
		printf("%I64d%c",ans[i],i<n?' ':'\n');
	return 0;
}
