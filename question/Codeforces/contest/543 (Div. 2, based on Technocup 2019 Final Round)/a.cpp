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
const int maxn= 1000;
int p[maxn],s[maxn],c[maxn],Max[maxn];
int n,m,k;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &m,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for (int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		Max[s[i]]=max(Max[s[i]],p[i]);
	}
	int ans=0;
	for (int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		if (p[x]!=Max[s[x]]){
			ans++;
		}
	}
	printf("%d",ans);
}
