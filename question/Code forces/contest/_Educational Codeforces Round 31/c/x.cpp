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
int p[maxn],vis[maxn],sta[maxn];
int n,la,i,x,cnt;
void dfs(int o){
	if (vis[o])
		return;
	vis[o]= 1;
	cnt++;
	dfs(p[o]);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&p[i]);
	for (i= 1;i<=n;i++)
		if (!vis[i]){
			cnt= 0;
			dfs(i);
			sta[++la]= cnt;
		}
	sort(sta+1,sta+la+1);
	if (la>1){
		sta[la-1]+= sta[la];
		la--;
	}
	ll ans= 0;
	for (i= 1;i<=la;i++)
		ans+= (ll)sta[i]*sta[i];
	printf("%I64d",ans);
	return 0;
}
