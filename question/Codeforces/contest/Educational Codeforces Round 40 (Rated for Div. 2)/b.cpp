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
int ans,n;
bool ok(int o){
	for (int i=1;i<=o;i++)
		if (s[i]!=s[o+i])
			return false;
	return true;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;2*i<=n;i++)
		if (ok(i)){
			ans=i;
		}
	printf("%d",min(n-ans+1,n));
	return 0;
}
