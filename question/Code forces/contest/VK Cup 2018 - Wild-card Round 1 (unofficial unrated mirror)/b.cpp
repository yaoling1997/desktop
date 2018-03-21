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
int n,ans;
int gcd(int a,int b){
	if (!b)
		return a;
	return gcd(b,a%b);
}
void solve(){
	int g=0;
	for (int i=1;i<=n;i++)
		g=gcd(g,b[i]);
	for (int i=1;i<=n;i++)
		ans+=b[i]/g-1;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++)
		b[i]=a[i+1]-a[i];
	n--;
	solve();
	printf("%d",ans);
	return 0;
}
