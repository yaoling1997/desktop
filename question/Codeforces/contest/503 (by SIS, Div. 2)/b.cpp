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
int f[maxn],vis[maxn];
int n,tim,ans;
void solve(int o){
	if (vis[o]==tim){
		ans=o;
		return;
	}
	vis[o]=tim;
	solve(f[o]);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&f[i]);
	for (int i=1;i<=n;i++){
		tim++;
		solve(i);
		printf("%d ",ans);
	}
	return 0;
}
