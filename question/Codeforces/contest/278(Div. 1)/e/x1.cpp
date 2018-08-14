#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 2e5;
char map[maxn][15],s[5];
bool vis[maxn][15];
int n,m,q,i,x,y;
void go(int x,int y){
	if (x<1||y<1||x>n||y>m){
		printf("%d %d\n",x, y);
		return;
	}
	if (vis[x][y]){
		printf("-1 -1\n");
		return;
	}
	vis[x][y]= 1;
	switch (map[x][y]){
	case '<':go(x,y-1);break;
	case '^':go(x-1,y);break;
	case '>':go(x,y+1);break;
	default:printf("shame on you!\n");break;
	}vis[x][y]= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d%d%d",&n, &m, &q);
	for (i= 1;i<=n;i++)
		scanf("%s",map[i]+1);
	for (i= 1;i<=q;i++){
		scanf("%s%d%d",s+1, &x, &y);
		if (s[1]=='A')
			go(x,y);
		else {
			scanf("%s",s+1);
			map[x][y]= s[1];
		}
	}return 0;
}
