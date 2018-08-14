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
int len,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	len=strlen(s+1);
	for (int i=2;i<len;i++)
		if (s[i-1]!='.'&&s[i]!='.'&&s[i+1]!='.')
			if (s[i-1]!=s[i]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
				ans++;
	printf("%s",ans?"Yes":"No");
	return 0;
}
