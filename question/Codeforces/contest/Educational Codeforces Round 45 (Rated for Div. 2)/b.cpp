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
int n,k,l;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		if (a[i]!=a[i-1]){
			l++;
			a[l]=a[i];
			b[l]=1;
		}else b[l]++;			
	int ans=0;
	for (int i=1;i<l;i++)
		if (a[i]<a[i+1]&&a[i+1]<=a[i]+k)
			ans+=b[i];
	ans=n-ans;
	printf("%d",ans);
	return 0;
}
