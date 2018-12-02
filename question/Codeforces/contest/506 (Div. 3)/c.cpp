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
int a[maxn],b[maxn];
int n,p,q;
int solve(int p){
	int l=-1,r=1e9+1;
	for (int i=1;i<=n;i++){
		if (i==p)
			continue;
		l=max(l,a[i]);
		r=min(r,b[i]);
	}
	return max(r-l,0);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i], &b[i]);
		if (!p||a[i]>a[p]||(a[i]==a[p]&&b[i]<b[p]))
			p=i;
		if (!q||b[i]<b[q]||(b[i]==b[q]&&a[i]>a[q]))
			q=i;
	}
	int ans,ans1,ans2;
	ans1=solve(p);
	ans2=solve(q);
	ans=max(ans1,ans2);
	printf("%d",ans);
	return 0;
}
