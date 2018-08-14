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
int n,a,b,c,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%d%d%d",&a, &b, &c);
	n--;
	if (n==0)
		;
	else if (n==1)
		ans= min(a,b);
	else
		ans= min(a,b)+(n-1)*min(min(a,b),c);
	printf("%d",ans);
}
