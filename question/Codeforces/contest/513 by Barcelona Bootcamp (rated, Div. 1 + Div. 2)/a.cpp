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
char s[maxn];
int n;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	int cnt=0;
	for (int i=1;i<=n;i++)
		cnt+=s[i]=='8';
	int ans;
	ans=min(cnt,n/11);
	printf("%d",ans);
	return 0;
}
