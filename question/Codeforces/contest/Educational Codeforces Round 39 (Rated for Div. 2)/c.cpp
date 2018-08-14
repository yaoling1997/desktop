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
int n,now='a';
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	n= strlen(s+1);
	for (int i=1;i<=n;i++)
		if (s[i]<=now){
			s[i]=now;
			now++;
			if (now>'z')
				break;
		}
	if (now>'z')
		printf("%s",s+1);
	else printf("-1");
	return 0;
}
