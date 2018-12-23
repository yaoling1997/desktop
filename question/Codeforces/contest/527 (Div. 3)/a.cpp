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
const int maxn= 5e2;
char s[maxn];
int t;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&t);
	int n,k;
	while (t--){
		scanf("%d%d",&n, &k);
		memset(s,0,sizeof(s));
		for (int i=0;i<n;i++)
			s[i]=i%k+'a';
		printf("%s\n",s);
	}
	return 0;
}
