#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 2e5,base= 320;
struct node{
	int o,x,y;
};
bool vis[maxn][15];
node f[maxn][15];
char map[maxn][15],s[5];
int n,m,q,i,j,x,y;
bool out(int x,int y){
	return x<1||y<1||x>n||y>m;
}
int num(int x){
	return x/base+(x%base!=0);
}
node dfs(int o,int x,int y){
	if (num(x)!=o) return (node){1,x,y};
	if (f[x][y].o) return f[x][y];
	if (vis[x][y]) return (node){-1,0,0};
	vis[x][y]= 1;
	int xx= x,yy= y;
	if (map[x][y]=='<') yy--;
	else if (map[x][y]=='^') xx--;
	else if (map[x][y]=='>') yy++;
	else {
		printf("orz浪哥！\n");
		return (node){0,0,0};
	}
	if (out(xx,yy)) f[x][y]= (node){1,xx,yy};
	else f[x][y]= dfs(o,xx,yy);
	return f[x][y];
}
void print(int x,int y){
	for (;;){
		if (out(x,y)){
			printf("%d %d\n",x, y);
			return;
		}
		if (f[x][y].o<0){
			printf("-1 -1\n");
			return;
		}
		node null_ge= f[x][y];
		x= null_ge.x;
		y= null_ge.y;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &m, &q);
	for (i= 1;i<=n;i++)
		scanf("%s",map[i]+1);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			dfs(num(i),i,j);
	for (int Q= 1;Q<=q;Q++){
		scanf("%s%d%d",s+1, &x, &y);
		if (s[1]=='A'){
			print(x,y);
		}else {
			scanf("%s",s+1);
			map[x][y]= s[1];
			int top= (num(x)-1)*base+1;
			int bot= min(num(x)*base,n);
			for (i= top;i<=bot;i++)
				for (j= 1;j<=m;j++){
					vis[i][j]= 0;
					f[i][j]= (node){0,0,0};
				}
			for (i= top;i<=bot;i++)
				for (j= 1;j<=m;j++)
					dfs(num(i),i,j);
		}
	}return 0;
}
