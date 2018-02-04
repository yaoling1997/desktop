#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int b[maxn],t[maxn],ans[maxn];
int i,j,k,p,n;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&t[i]);
	for (i= 1;i<=n;i++){
		memset(b,0,sizeof(b));
		p= 0;
		for (j= i;j<=n;j++){
			b[t[j]]++;
			if (b[t[j]]>b[p])
				p= t[j];
			else if (b[t[j]]==b[p]&&t[j]<p)
				p= t[j];
			ans[p]++;
		}
	}
	for (i= 1;i<=n;i++)
		printf("%d%c",ans[i], i<n?' ':'\n');
	return 0;
}