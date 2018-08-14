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
int sum[maxn];
char s[maxn];
int n,i,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	int len= strlen(s+1);
	for (i= 1;i<=len;i++)
		sum[i]=sum[i-1]+(s[i]=='Q');
	for (i= 1;i<=len;i++)
		if (s[i]=='A')
			ans+= sum[i-1]*(sum[len]-sum[i]);
	printf("%d",ans);
	return 0;
}
