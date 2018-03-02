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
char ans[maxn];
int n,tot;
bool isVowel(char c){
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y';
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		if (isVowel(s[i])&&isVowel(ans[tot]))
			continue;
		ans[++tot]=s[i];
	}
	printf("%s",ans+1);
}
