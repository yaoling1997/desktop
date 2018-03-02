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
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<n;i++)
		if (n%i==0)
			ans++;
	printf("%d",ans);
	return 0;
}
