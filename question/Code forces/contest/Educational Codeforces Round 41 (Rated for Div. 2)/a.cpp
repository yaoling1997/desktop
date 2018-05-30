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
const int maxn= 5e5,oo=1e9;
int a[maxn];
int n,m,x;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=m;i++){
		scanf("%d",&x);
		a[x]++;
	}
	int ans=oo;
	for (int i=1;i<=n;i++){
		ans=min(ans,a[i]);
	}
	printf("%d",ans);
}
