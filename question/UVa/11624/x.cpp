#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2000,oo= 1e9;
struct node{
	int x,y,t;
}M[5];
queue<node> Q;
char s[maxn][maxn];
int vis[maxn][maxn],f[maxn][maxn];
int n,m,i,j,X,Y,ans,T;
void init(){
	memset(vis,-1,sizeof(vis));
	memset(f,-1,sizeof(f));
}
bool ok(int x,int y){
	return x>0&&y>0&&x<=n&&y<=m&&s[x][y]!='#';
}
void bfs(){
	int i,j;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			if (s[i][j]=='F'){
				f[i][j]= 0;
				Q.push((node){i,j,0});
			}
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		for (i= 0;i<4;i++){
			int xx= u.x+M[i].x,yy= u.y+M[i].y;
			if (!ok(xx,yy)||f[xx][yy]!=-1) continue;
			f[xx][yy]= f[u.x][u.y]+1;
			Q.push((node){xx,yy,0});
		}
	}
}
bool find(int x,int y){
	vis[x][y]= 0;
	Q.push((node){x,y,0});
	int i;
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		for (i= 0;i<4;i++){
			int xx= u.x+M[i].x,yy= u.y+M[i].y;
			if (!ok(xx,yy)||vis[xx][yy]!=-1) continue;
			if (f[xx][yy]>-1&&f[xx][yy]<=u.t+1) continue;
			vis[xx][yy]= u.t+1;
			Q.push((node){xx,yy,u.t+1});
		}
	}
	ans= oo;
	for (i= 1;i<=n;i++){
		if (vis[i][1]!=-1) ans= min(ans,vis[i][1]+1);
		if (vis[i][m]!=-1) ans= min(ans,vis[i][m]+1);
	}
	for (i= 1;i<=m;i++){
		if (vis[1][i]!=-1) ans= min(ans,vis[1][i]+1);
		if (vis[n][i]!=-1) ans= min(ans,vis[n][i]+1);
	}
	return ans!=oo;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	M[0]= (node){-1,0};
	M[1]= (node){0,1};
	M[2]= (node){1,0};
	M[3]= (node){0,-1};	
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n, &m);
		init();
		for (i= 1;i<=n;i++)
			scanf("%s",s[i]+1);
		for (i= 1;i<=n;i++)
			for (j= 1;j<=m;j++)
				if (s[i][j]=='J'){
					X= i;
					Y= j;
					s[i][j]= '.';
				}
		bfs();
		if (find(X,Y)) printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}return 0;
}
