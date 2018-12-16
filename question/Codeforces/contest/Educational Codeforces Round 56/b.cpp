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
int t;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&t);
	while (t--){
		scanf("%s",s+1);
		int len= strlen(s+1);
		sort(s+1,s+len+1);
		if (s[1]==s[len])
			printf("-1\n");
		else
			printf("%s\n",s+1);
	}
	return 0;
}
