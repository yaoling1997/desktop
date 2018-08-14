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
int sta[maxn];
char s[maxn],t[maxn];
int n,la;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d\n",&n);
	scanf("%s%s",s+1,t+1);
	if (!is_permutation(s+1,s+n+1,t+1)){
		printf("-1");
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if (s[j]==t[n-i+1]){
				sta[++la]=n;
				sta[++la]=j-1;
				sta[++la]=1;
				reverse(s+1,s+n+1);
				rotate(s+1,s+(n-(j-1)+1),s+n+1);
				reverse(s+1,s+(j-1)+1);				
				rotate(s+1,s+n,s+n+1);
				break;
			}
	printf("%d\n",la);
	for (int i=1;i<=la;i++)
		printf("%d%c",sta[i],i<la?' ':'\n');
	return 0;
}
