#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 2e5,oo= 1e9;
struct point{
	int x,y,h;
}a[maxn],w[maxn];
vector<int> g[maxn];
int M[maxn];
int i,j,n,x,y,ans,Max_x,bl;
/////////////////////////
int o1,o2,o3,o4;
/////////////////////////
bool cmp(point a,point b){
	return a.y-a.x<b.y-b.x||(a.y-a.x==b.y-b.x&&a.x<=b.x&&a.y<=b.y);
}
bool cmp1(point a,point b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
bool cmp2(point a,point b){
	return a.h<b.h;
}
int b(int a,int b){
	if (M[a]<b) return oo;
	return g[a][b];
}
int main()
{
	bl= 1;
	scanf("%d",&n);
	for (i= 0;i<maxn;i++)
		M[i]= -1;
	for (i= 1;i<=n;i++){
		scanf("%d%d",&x, &y);
		a[i]= (point){x,y};
		M[x]= max(M[x],y);
		Max_x= max(Max_x,x);
	}
	for (i= 0;i<=Max_x;i++)
		for (j= 0;j<=M[i];j++)
			g[i].push_back(0);
	for (i= 1;i<=n;i++){
		scanf("%d",&w[i].x);
		w[i].y= i;
	}
	sort(a+1,a+n+1,cmp);
	sort(w+1,w+n+1,cmp1);
	for (i= 1;i<=n;i++){
		if (a[i].y-a[i].x!=w[i].x){
			bl= 0;
			break;
		}
		a[i].h= w[i].y;
		g[a[i].x][a[i].y]= w[i].y;
	}
	if (bl){
		for (i= 0;i<=Max_x;i++)
			for (j= 0;j<=M[i];j++){
				o1= g[i][j];
				if (g[i][j]<b(i,j+1)&&g[i][j]<b(i+1,j))
					continue;
				bl= 0;
				goto pn;
			}
	}
 pn:
	if (bl){
		printf("YES\n");
		sort(a+1,a+n+1,cmp2);
		for (i= 1;i<=n;i++)
			printf("%d %d\n",a[i].x,a[i].y);
	}else {
		printf("NO\n");
	}return 0;
}
