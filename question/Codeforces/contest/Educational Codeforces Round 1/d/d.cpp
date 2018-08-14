#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 1e3+1e2;
struct node{
	int x,y;
	node(int x= 0,int y= 0):x(x),y(y){}
};
node M[4];
char s[maxn][maxn];
int f[maxn][maxn],vis[maxn][maxn][4];//down,up,right,left
queue<node> Q;
vector<int> a;
int n,m,i,j,k,now,x,y;
void bfs(int x,int y){
	now++;
	Q.push(node(x,y));
	f[x][y]= now;
	int ans= 0;
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		int i;
		for (i= 0;i<4;i++){
			int xx= u.x+M[i].x,yy= u.y+M[i].y;
			if (s[xx][yy]=='*'){
				if (vis[xx][yy][i]) continue;
				vis[xx][yy][i]= 1;
				ans++;
			}else {
				if (f[xx][yy]) continue;
				f[xx][yy]= now;
				Q.push(node(xx,yy));
			}
		}
	}
	a.push_back(ans);
}
int main()
{
	scanf("%d%d%d",&n, &m, &k);
	M[0]= node(1,0);
	M[1]= node(-1,0);
	M[2]= node(0,-1);
	M[3]= node(0,1);
	for (i= 1;i<=n;i++)
		scanf("%s",s[i]+1);
	now= 0;
	for (i= 1;i<=k;i++){
		scanf("%d%d",&x, &y);
		if (!f[x][y]) bfs(x,y);
		printf("%d\n",a[f[x][y]-1]);
	}return 0;
}
