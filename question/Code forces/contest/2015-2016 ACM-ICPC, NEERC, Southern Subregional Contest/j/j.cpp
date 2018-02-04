#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 20;
struct status{
	int x,y,d;
};
struct move{
	int x,y;
};
move M[4];
queue<status> Q;
status init;
char map[maxn][maxn];
int f[maxn][maxn][10];
int vis[maxn][maxn];
int w,h,i,j,k,x,y,z,ans;
int idx(char x){
	if (x=='U') return 0;
	if (x=='R') return 1;
	if (x=='D') return 2;
	if (x=='L') return 3;
	return 1e9;
}
int main()
{	
	M[0].x= -1;
	M[1].y= 1;
	M[2].x= 1;
	M[3].y= -1;
	scanf("%d%d",&w, &h);
	for (i= 1;i<=w;i++){
		scanf("%s",map[i]+1);
		for (j= 1;j<=h;j++)
			if ('A'<=map[i][j]&&map[i][j]<='Z'){
				init= (status){i,j,idx(map[i][j])};
				map[i][j]= '.';
			}
	}
	vis[init.x][init.y]= 1;
	f[init.x][init.y][init.d]= 1;
	Q.push(init);
	while (!Q.empty()){
		status u= Q.front();
		Q.pop();
		x= u.x,y= u.y,k= u.d;
		int xx= u.x+M[k].x;
		int yy= u.y+M[k].y;
		if (map[xx][yy]=='.'){
			if (f[xx][yy][k]) continue;
			f[xx][yy][k]= vis[xx][yy]= 1;
			Q.push((status){xx,yy,k});
		}else {
			k= (k+1)%4;
			if (f[x][y][k]) continue;
			Q.push((status){x,y,k});
		}
	}
	for (i= 1;i<=w;i++)
		for (j= 1;j<=h;j++)
			ans+= vis[i][j];
	printf("%d",ans);
	return 0;
}
