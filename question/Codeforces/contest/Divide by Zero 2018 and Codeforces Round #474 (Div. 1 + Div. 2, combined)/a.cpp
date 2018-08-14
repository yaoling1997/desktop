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
int solve(){
	int a=0,b=0,c=0;
	int i=1;
	while (i<=n&&s[i]=='a'){
		i++;
		a++;
	}
	while (i<=n&&s[i]=='b'){
		i++;
		b++;
	}
	while (i<=n&&s[i]=='c'){
		i++;
		c++;
	}
	if (i!=n+1)
		return 0;
	if (!a||!b||!c)
		return 0;
	return a==c||b==c;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	n= strlen(s+1);
	ans=solve();
	printf("%s",ans?"YES":"NO");
	return 0;
}
