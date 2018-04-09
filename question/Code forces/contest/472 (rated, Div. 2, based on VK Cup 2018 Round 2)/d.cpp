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
int a[maxn],m[maxn];
ll ans;
int n,tmp;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&m[i]);
		tmp=max(tmp,m[i]+1);
		a[i]=tmp;
	}
	for (int i=n;i>1;i--)
		a[i-1]=max(a[i-1],a[i]-1);
	for (int i=1;i<=n;i++)
		ans+=max(a[i]-m[i]-1,0);
	printf("%I64d",ans);
	return 0;
}
