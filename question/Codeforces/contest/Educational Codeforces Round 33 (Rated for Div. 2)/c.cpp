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
const int maxn= 5e5,oo=2e9;
int c[maxn],f[maxn],cf[maxn];
int n,m;
ll ans;
int find(int o){
	if (o==f[o])
		return o;
	return f[o]=find(f[o]);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		f[i]=i;
		cf[i]=oo;
	}
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		f[find(x)]=find(y);
	}
	for (int i=1;i<=n;i++)
		cf[find(i)]=min(cf[find(i)],c[i]);
	for (int i=1;i<=n;i++)
		if (cf[i]!=oo)
			ans=ans+cf[i];
	printf("%I64d",ans);
	return 0;
}
