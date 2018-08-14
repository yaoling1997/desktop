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
const int maxn= 200,maxm=1e5,M=26;
int f[105][105][2][30];
int h[maxn],nex[maxm],des[maxm],w[maxm],vis[maxn];
char s[10];
int n,m;
int dfs(int M,int L,int r,int ascii){
	if (f[M][L][r][ascii]!=-1)
		return f[M][L][r][ascii];
	f[M][L][r][ascii]=0;
	int o= r==1?M:L;
	for (int i=h[o];i;i=nex[i]){
		int v=des[i],W=w[i];
		if (W<ascii)
			continue;
		if (!dfs(r==1?v:M,r==0?v:L,r^1,W)){
			f[M][L][r][ascii]=1;
			break;
		}
	}
	return f[M][L][r][ascii];
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif	
	scanf("%d%d",&n, &m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d%s",&x, &y, s);
		des[i]=y;
		w[i]=s[0]-'a'+1;
		nex[i]=h[x];
		h[x]=i;
	}
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;k<2;k++)
				for (int z=0;z<30;z++)
					f[i][j][k][z]=-1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			if (dfs(i,j,1,0))
				printf("A");
			else
				printf("B");
		printf("\n");
	}
	return 0;
}
