#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 4*1e3,maxm= 4*1e6;
struct node{
	int x,y;
};
bool cmp(node a,node b){return a.x+a.y>b.x+b.y;}
node a[maxm];
int c[maxn][maxn];
int i,j,top,x,y,n,m;
int main()
{
	scanf("%d %d\n",&n, &m);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++){
			top++;char ch1,ch2;
			scanf("%c%c",&ch1,&ch2);
			a[top].x= ch1-'0', a[top].y= ch2-'0';
			scanf("%c",&ch1);
			if (a[top].x==1 && a[top].y==0)
				swap(a[top].x,a[top].y);
		}
	sort(a+1,a+top+1,cmp);
	x= 1;y= 1;
	for (i= 1;i<=top;i++){
		if (a[i].x+a[i].y==2)
			c[x][y]= c[x][y+1]= 1;
		else if (a[i].x+a[i].y==1){
			if (c[x-1][y]+c[x-1][y+1]==1){
				if (c[x-1][y]){
					c[x][y]= 0;
					c[x][y+1]= 1;
				}else {
					c[x][y]= 1;
					c[x][y+1]= 0;
				}
			}else {
				c[x][y]= 0;
				c[x][y+1]= 1;
			}
		}else c[x][y]= c[x][y+1]= 0;
		if (x%2){
			y+= 2;
			if (y>2*m){
				x++;y-=2;
			}
		}else {
			y-= 2;
			if (y<0){
				x++;y+= 2;
			}
		}
	}
	for (i= 1;i<=n;i++){
		for (j= 1;j<=2*m;j+= 2){
			printf("%d%d",c[i][j],c[i][j+1]);
			if (!(i==n && j==2*m-1)) printf(" ");
		}
		if (i!=n)
			printf("\n");
	}
	return 0;
}
