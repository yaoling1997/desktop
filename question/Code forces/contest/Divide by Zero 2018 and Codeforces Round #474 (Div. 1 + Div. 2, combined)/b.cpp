#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
priority_queue<int> Q;
int a[maxn];
int n,k1,k2,k;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &k1, &k2);
	k=k1+k2;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[i]=abs(a[i]-x);
		Q.push(a[i]);
	}
	while (k){
		k--;
		int u=Q.top();
		Q.pop();
		u=abs(u-1);
		Q.push(u);
	}
	ll ans=0;
	while (!Q.empty()){
		ll u=Q.top();
		Q.pop();
		ans+=u*u;
	}
	printf("%I64d",ans);
	return 0;
}
