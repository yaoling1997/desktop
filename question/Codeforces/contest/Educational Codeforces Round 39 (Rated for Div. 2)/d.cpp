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
const int maxn= 5e2+10,oo=1e9;
char s[maxn];
vector<int> V;
int f[maxn][maxn],g[maxn][maxn];
int n,m,K;
void init(){
	for (int i=0;i<=n;i++)
		for (int j=0;j<=K;j++)
			f[i][j]= g[i][j]=oo;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &m, &K);
	init();
	for (int i=1;i<=n;i++){
		V.clear();
		scanf("%s",s+1);
		for (int j=1;j<=m;j++){
			if (s[j]=='1')
				V.pb(j);
		}
		int len= V.size();
		for (int j=0;j<=len;j++){
			int x=len-j;
			if (len==0||x==0){
				f[i][j]=0;
			}else {
				int Min=oo;
				for (int k=0;k+x-1<=len-1;k++)
					Min= min(Min,V[k+x-1]-V[k]+1);
				f[i][j]=Min;
			}
		}
	}
	g[0][0]=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=K;j++){
			for (int k=0;k<=j;k++)
				g[i][j]=min(g[i][j],g[i-1][j-k]+f[i][k]);
			if (j>0)
				g[i][j]=min(g[i][j],g[i][j-1]);
		}
	printf("%d",g[n][K]);
	return 0;
}
