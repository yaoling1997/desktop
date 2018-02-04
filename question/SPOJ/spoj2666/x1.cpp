#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e5,oo= 1e9;
struct edge{
	int v,w;
};
vector<edge> g[maxn];
char s[10];
int c[maxn];
int n,m,i,j,x,y,z,ans;
void dfs(int o,int fa,int s){
	if (!c[o]) ans= max(ans,s);
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i].v,w= g[o][i].w;
		if (v==fa) continue;
		dfs(v,o,s+w);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<n;i++){
		scanf("%d%d%d",&x, &y, &z);
		g[x].push_back((edge){y,z});
		g[y].push_back((edge){x,z});
	}scanf("%d",&m);
	for (int mm= 1;mm<=m;mm++){
		scanf("%s",s+1);
		if (s[1]=='C'){
			scanf("%d",&x);
			c[x]^= 1;
		}else {
			ans= -oo;
			for (i= 1;i<=n;i++)
				if (!c[i])
					dfs(i,0,0);				
			if (ans==-oo)
				printf("They have disappeared.\n");
			else printf("%d\n",ans);
		}
	}return 0;
}
