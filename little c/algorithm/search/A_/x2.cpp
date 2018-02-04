#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 4000;
struct node{
	int x,y;
};
node d[maxn*maxn];
node l[maxn*maxn];
int a[maxn][maxn],vis[maxn][maxn];
int n,m,x,y,i,j,bl,top,f,r;
bool com(int x,int y){
	return a[x][y]!=1 && !vis[x][y];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("3.out","w",stdout);
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
	f= 0;r= 1;l[1].x= x;l[1].y= y;vis[x][y]= 1;
	while (f<r){
		x= l[++f].x;y= l[f].y;
		if (a[x+1][y]==2){
			bl= 1;break;
		}else if (a[x+1][y]==0 && !vis[x+1][y]){
			vis[x+1][y]= 1;
			l[++r].x= x+1;l[r].y= y;
		}
		if (a[x-1][y]==2){
			bl= 1;break;
		}else if (a[x-1][y]==0 && !vis[x-1][y]){
			vis[x-1][y]= 1;
			l[++r].x= x-1;l[r].y= y;
		}
		if (a[x][y+1]==2){
			bl= 1;break;
		}else if (a[x][y+1]==0 && !vis[x][y+1]){
			vis[x][y+1]= 1;
			l[++r].x= x;l[r].y= y+1;
		}
		if (a[x][y-1]==2){
			bl= 1;break;
		}else if (a[x][y-1]==0 && !vis[x][y-1]){
			vis[x][y-1]= 1;
			l[++r].x= x;l[r].y= y-1;
		}				
	}
	if (bl) printf("yes");
	else printf("no");
	return 0;
}
