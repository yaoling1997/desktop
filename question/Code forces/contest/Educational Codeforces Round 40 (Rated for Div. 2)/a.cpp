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
int n,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	s[n+1]=s[n];
	for (int i=1;i<=n;i++)
		if (s[i]!=s[i+1]){
			ans++;
			i++;
		}else
			ans++;
	printf("%d",ans);
	return 0;
}
