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
const int maxn= 6e5+10;
const int mo= 998244353,oo=1e9;
int h[maxn],des[maxn],nex[maxn],v[maxn],vis[maxn];
int t,n,m,tot,tim,oddNum;
void init(){
	for (int i=0;i<=n;i++)
		h[i]=vis[i]=0;
	tot=0;
}
void addedge(int x,int y){
	nex[++tot]=h[x];
	des[tot]=y;
	h[x]=tot;
}
void dfs(int o,int z){
	vis[o]=tim;
	v[o]=z;
	if (z&1)
		oddNum++;
	for (int i=h[o];i;i=nex[i]){
		int u=des[i];
		if (vis[u]==tim){
			if (v[u]==z)
				oddNum=-oo;			
		}else
			dfs(u,z^1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n, &m);
		init();
		int x,y;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&x, &y);
			addedge(x,y);
			addedge(y,x);
		}
		ll ans=1;
		for (int i=1;i<=n;i++)
			if (vis[i]==0){
				ll cnt=0,x;
				oddNum=0;
				tim++;
				dfs(i,0);
				if (oddNum<0){
					ans*=0;
					continue;
				}
				x=1;
				for (int j=1;j<=oddNum;j++)
					x=x*2%mo;
				cnt+=x;
				oddNum=0;
				tim++;
				dfs(i,1);
				x=1;
				for (int j=1;j<=oddNum;j++)
					x=x*2%mo;
				cnt=(cnt+x)%mo;
				ans=ans*cnt%mo;
			}
		printf("%I64d\n",ans);
	}
}
