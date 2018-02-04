#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 50;
struct node{
	int x,y,d,c,t;
};
struct move{
	int x,y;
}M[5];
queue<node> Q;
char s[30][30];
int vis[30][30][10][10];
int n,m,i,j,x,y,ans,cnt,sx,sy,tx,ty;
void init(){
	memset(vis,0,sizeof(vis));
	ans= -1;
}
bool ok(int x,int y){
	return x>0&&y>0&&x<=n&&y<=m&&s[x][y]!='#';
}
void bfs(int x,int y){//0N1E2S3L
	while (!Q.empty()) Q.pop();
	vis[x][y][0][0]= 1;
	Q.push((node){x,y,0,0,0});
	while (!Q.empty()){
		node u= Q.front();
		int i;
		Q.pop();
		for (i= 0;i<= 3;i++){//turn direction
			if (vis[u.x][u.y][i][u.c]) continue;
			if ((i-u.d)%2==0) continue;
			vis[u.x][u.y][i][u.c]= 1;
			Q.push((node){u.x,u.y,i,u.c,u.t+1});
		}		
		int xx= u.x+M[u.d].x;
		int yy= u.y+M[u.d].y;
		if (!ok(xx,yy)) continue;
		int nc= (u.c+1)%5;
		if (vis[xx][yy][u.d][nc]) continue;
		vis[xx][yy][u.d][nc]= 1;
		if (xx==tx&&yy==ty&&!nc){
			ans= u.t+1;
			return;
		}
		Q.push((node){xx,yy,u.d,nc,u.t+1});		
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	M[0]= (move){-1,0};
	M[1]= (move){0,1};
	M[2]= (move){1,0};
	M[3]= (move){0,-1};
	while (scanf("%d%d",&n, &m)>0){
		if (!n) break;
		cnt++;
		init();
		for (i= 1;i<=n;i++){
			scanf("%s",s[i]+1);
			for (j= 1;j<=m;j++){
				if (s[i][j]=='S'){
					sx= i;
					sy= j;
				}
				if (s[i][j]=='T'){
					tx= i;
					ty= j;
				}				
			}
		}
		bfs(sx,sy);
		if (cnt>1) printf("\n");
		printf("Case #%d\n",cnt);
		if (ans==-1)
			printf("destination not reachable\n");
		else printf("minimum time = %d sec\n",ans);
	}return 0;
}
