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
int n,m,ans;
void solve(){
	ll A=0,B=0;
	int j=1;
	for (int i=1;i<=n;i++){
		A+=a[i];
		while (j<=m&&B<A){
			B+=b[j];
			j++;
		}
		if (A==B)
			ans++;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	solve();
	printf("%d",ans);
	return 0;
}
