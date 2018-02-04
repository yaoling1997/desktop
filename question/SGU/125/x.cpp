#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
int b[10][10],a[10][10],c[10][10];
int n,i,j,bl;
void modify(int x,int y,int v,int o){
	if (x<1||y<1) return;
	if (v>a[x][y]) c[x][y]+= o;
}
int check(int x,int y,int v){
	if (x<1||y<1) return 0;
	return a[x][y]>v;
}
void update(int x,int y,int o){
	modify(x-1,y,a[x][y],o);
	modify(x,y-1,a[x][y],o);
	c[x][y]+= o*check(x-1,y,a[x][y]);
	c[x][y]+= o*check(x,y-1,a[x][y]);
}
void dfs(int x,int y){
	int i;
	if (y>n){
		x++;
		y= 1;
	}
	if (x>n){
		for (i= 1;i<=n;i++)
			if (c[n][i]!=b[n][i]) return;
		bl= 1;
		return;
	}
	for (i= 0;i<=9;i++){
		a[x][y]= i;
		update(x,y,1);
		if (x>=2&&c[x-1][y]!=b[x-1][y]);
		else dfs(x,y+1);
		if (bl) return;
		update(x,y,-1);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			scanf("%d",&b[i][j]);
	dfs(1,1);
	if (bl){
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++)
				printf("%d%c",a[i][j],j<n?' ':'\n');
	}else printf("NO SOLUTION");
	return 0;
}
