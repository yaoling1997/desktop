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
int ans,n,k,x;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &k);
	ans=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (k%x==0&&k/ans>k/x)
			ans=x;
	}
	printf("%d",k/ans);
}
