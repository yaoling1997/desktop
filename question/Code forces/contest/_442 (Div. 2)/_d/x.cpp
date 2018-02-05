#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 2000;
typedef pair<int,int> PA;
PA Move[4];
char s[maxn][maxn];
int vis[maxn][maxn];
int n,m,i,j,K;
bool out(int x,int y){
	return x<1||y<1||x>n||y>m;
}
void solve(int x1,int y1,int x2,int y2){
	int i,j;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			vis[i][j]= -1;
	vis[x1][y1]= 0;
	queue<PA> Q;
	Q.push(mp(x1,y1));
	while (!Q.empty()){
		PA u= Q.front();
		Q.pop();
		int x= u.first;
		int y= u.second;
		for (i= 0;i<4;i++){
			int xx= x;
			int yy= y;
			for (j= 1;j<=K;j++){
				xx+= Move[i].first;
				yy+= Move[i].second;
				if (s[xx][yy]=='#'||out(xx,yy))
					break;
				if (vis[xx][yy]==-1){
					vis[xx][yy]= vis[x][y]+1;
					Q.push(mp(xx,yy));
				}else if (vis[xx][yy]<=vis[x][y])
					break;
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &m, &K);
	Move[0]= mp(-1,0);
	Move[1]= mp(0,1);
	Move[2]= mp(1,0);
	Move[3]= mp(0,-1);
	for (i= 1;i<=n;i++)
		scanf("%s",s[i]+1);
	int x,y,xx,yy;
	scanf("%d%d%d%d",&x, &y, &xx, &yy);
	solve(x,y,xx,yy);
	printf("%d",vis[xx][yy]);
	return 0;
}
