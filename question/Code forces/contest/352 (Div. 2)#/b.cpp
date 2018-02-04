#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e5;
char s[maxn];
int a[500];
int n,i,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	if (n>26){
		printf("-1");
	}else {
		for (i= 1;i<=n;i++)
			a[s[i]]++;
		for (i= 'a';i<='z';i++)
			ans+= max(a[i]-1,0);
		printf("%d",ans);
	}return 0;
}