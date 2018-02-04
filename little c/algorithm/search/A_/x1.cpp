#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 4000,oo= 1e8;
struct node{
	int x,y,g,h;
};
node open[maxn*maxn];
int a[maxn][maxn],p[maxn][maxn][2],G[maxn][maxn],done[maxn][maxn];
char ch;
int n,m,x,y,i,j,k,time,top,fx,fy;
bool operator <(node a,node b){return a.g+a.h*11<b.g+b.h*11;}
void down(int o){
	int t= o;
	if (2*o<=top && open[2*o]<open[t]) t= 2*o;
	if (2*o+1<=top && open[2*o+1]<open[t]) t= 2*o+1;
	if (o!=t){
		swap(open[o],open[t]);
		down(t);
	}
}
void up(int o){
	while (o/2){
		if (open[o]<open[o/2])
			swap(open[o],open[o/2]);
		else break;
		o/= 2;
	}
}
int count(int x,int y){
	return abs(fx-x)+abs(fy-y);
}
void print(int x,int y){
	if (p[x][y][0]!=oo) 
		print(p[x][y][0],p[x][y][1]);
	printf("%d %d\n",x,y);
}
void choose(int x,int y){
	int g= open[1].g;
	if (G[x][y]>g+10){
		G[x][y]= g+10;
		p[x][y][0]= open[1].x;p[x][y][1]= open[1].y;
		open[++top].x= x;open[top].y= y;
		open[top].g= G[x][y];open[top].h= count(x,y);
		up(top);
	}
}
int  astar(){
	while (top){
		int x= open[1].x,y= open[1].y;
		if (done[x][y]) {open[1]= open[top--];down(1);continue;}
		done[x][y]= 1;		
		if (a[x+1][y]==2){
			p[x+1][y][0]= x;
			p[x+1][y][1]= y;
			//print(x+1,y);
			return 1;
		}else if (a[x+1][y]==0)
			choose(x+1,y);
		if (a[x-1][y]==2){
			p[x-1][y][0]= x;
			p[x-1][y][1]= y;
			//print(x-1,y);
			return 1;			
		}else if (a[x-1][y]==0)
			choose(x-1,y);
		if (a[x][y+1]==2){
			p[x][y+1][0]= x;
			p[x][y+1][1]= y;
			//print(x,y+1);
			return 1;			
		}else if (a[x][y+1]==0)
			choose(x,y+1);
		if (a[x][y-1]==2){
			p[x][y-1][0]= x;
			p[x][y-1][1]= y;
			//print(x,y-1);
			return 1;			
		}else if (a[x][y-1]==0)
			choose(x,y-1);
		open[1]= open[top--];
		down(1);
	}
	return 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d %d %d %d\n",&n, &m, &x, &y);
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++){
			G[i][j]= oo;
			scanf("%c",&ch);
			a[i][j]= ch-'0';
			if (a[i][j]==2) fx= i,fy= j;
		}
		scanf("\n");
	}
	for (i= 0;i<=n+1;i++)
		a[i][0]= a[i][m+1]= 1;
	for (i= 0;i<=m+1;i++)
		a[0][i]= a[n+1][i]= 1;
	open[++top].x= x;open[top].y= y;G[x][y]= 0;
	open[top].g= 0;open[top].h= count(x,y);p[x][y][0]= oo;
	if (astar()) printf("yes\n");
	else printf("no\n");
	return 0;
}
