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
const int maxn= 2e6;
int L[maxn];
int n,i,cnt;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&L[i]);
	int now= n+1;
	for (i=n;i>=1;i--){
		if (i<now)
			cnt++;
		now= min(now,i-L[i]);
	}
	printf("%d",cnt);
}
