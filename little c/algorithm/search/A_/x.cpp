#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 4000;
struct node{
	int x,y;
};
node d[maxn*maxn];
int a[maxn][maxn],vis[maxn][maxn];
int n,m,x,y,i,j,bl,top;
bool com(int x,int y){
	return a[x][y]!=1 && !vis[x][y];
}
void dfs(int x,int y){
	vis[x][y]= 1;
	if (a[x][y]==2) {d[++top]= (node){x,y};bl= 1;return;}
	if (com(x+1,y)) dfs(x+1,y);
	if (bl) {
		//d[++top]= (node){x,y};
		return;
	}
	if (com(x-1,y)) dfs(x-1,y);
	if (bl) {
		//d[++top]= (node){x,y};
		return;
	}	
	if (com(x,y+1)) dfs(x,y+1);
	if (bl) {
		//d[++top]= (node){x,y};
		return;
	}	
	if (com(x,y-1)) dfs(x,y-1);
	if (bl) {
		//d[++top]= (node){x,y};
		return;
	}	
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d %d\n",&n, &m, &x, &y);
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++){
			char c;
			scanf("%c",&c);
			a[i][j]= c-'0';
		}
		scanf("\n");
	}
	for (i= 0;i<=n+1;i++)
		a[i][0]= a[i][m+1]= 1;
	for (i= 0;i<=m+1;i++)
		a[0][i]= a[n+1][i]= 1;
	dfs(x,y);
	if (bl) printf("yes");
	else printf("no");
		/*while (top){
		printf("%d %d\n",d[top].x,d[top].y);
		top--;
		}*/
	return 0;
}
