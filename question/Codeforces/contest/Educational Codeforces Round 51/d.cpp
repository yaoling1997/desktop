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
struct node{
	int x,y;
}M[4];
int mo=998244353;
const int maxn= 1005;
int f[maxn][2*maxn][5];
int a[4][4],vis[4][4];
int b[4][4];
int tim,n,K;
void dfs(int i,int j){
	if (vis[i][j]==tim)
		return;
	vis[i][j]=tim;
	for (int k=0;k<4;k++){
		int x=i+M[k].x;
		int y=j+M[k].y;
		if (b[x][y]==b[i][j])
			dfs(x,y);
	}
}
int solve(int p,int q){
	int c[4]={1,2,2,1};
	memset(b,-1,sizeof(b));
	int x=p;
	for (int i=1;i<=2;i++){
		b[i][1]=x&1;
		x>>=1;
	}
	x=q;
	for (int i=1;i<=2;i++){
		b[i][2]=x&1;
		x>>=1;
	}
	tim++;
	int cnt=0;
	for (int i=1;i<=2;i++)
		for (int j=1;j<=2;j++){
			if (vis[i][j]==tim)
				continue;
			cnt++;
			dfs(i,j);
		}
	return cnt-c[p];
}
void update(int &a,int x){
	a=a+x;
	if (a>=mo)
		a-=mo;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	M[0]={-1,0};
	M[1]={0,1};
	M[2]={1,0};
	M[3]={0,-1};
	scanf("%d%d",&n, &K);
	f[1][1][0]=f[1][1][3]=1;
	f[1][2][1]=f[1][2][2]=1;
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			a[i][j]=solve(i,j);
	for (int i=1;i<n;i++)
		for (int ii=1;ii<=K;ii++)
			for (int j=0;j<4;j++)
				for (int k=0;k<4;k++)
					update(f[i+1][ii+a[j][k]][k],f[i][ii][j]);
	int ans=0;
	for (int i=0;i<4;i++)
		update(ans,f[n][K][i]);
	printf("%d",ans);
	return 0;
}
