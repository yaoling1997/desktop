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
const int maxn= 200,oo=1e9;
struct node{
	int x,y;
}M[10];
char s[10][maxn][maxn];
int a[maxn][maxn];
int per[10],vis[maxn][maxn];
int n,ans,tim;
int dfs(int x,int y,int c){
	if (x>2*n||y>2*n)
		return 0;
	if (vis[x][y]==tim)
		return 0;
	vis[x][y]=tim;
	int re=0;
	re+=abs(c-a[x][y]);
	re+=dfs(x+1,y,c^1);
	re+=dfs(x,y+1,c^1);
	return re;
}
void solve(){
	for (int k=1;k<=4;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				a[i+M[k].x*n][j+M[k].y*n]=s[per[k]][i][j]-'0';
	tim++;
	int re;
	re=dfs(1,1,0);
	ans=min(ans,re);
	tim++;
	re=dfs(1,1,1);
	ans=min(ans,re);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d\n",&n);
	for (int k=1;k<=4;k++){
		for (int i=1;i<=n;i++)
			scanf("%s",s[k][i]+1);
		scanf("\n");
	}
	M[1]=(node){0,0};
	M[2]=(node){1,0};
	M[3]=(node){0,1};
	M[4]=(node){1,1};
	for (int i=1;i<=4;i++)
		per[i]=i;
	ans=oo;
	do{
		solve();
	}while (next_permutation(per+1,per+4+1));
	printf("%d",ans);
	return 0;
}
