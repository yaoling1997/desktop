#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e4,maxm= 2e5;
struct point{
	int x,y,h;
}p[maxn],q[maxn];
struct line{
	point a,b;
}L[maxn];
vector<int> g[maxn];
int X[maxn],Y[maxn],a[maxm];
int n,m,i,j,k,ans,bl,cnt,x,y,la,sum,l,r;
bool cmpx(int a,int b){
	return p[a].x<p[b].x||(p[a].x==p[b].x&&p[a].y<p[b].y);
}
bool cmpy(int a,int b){
	return p[a].y<p[b].y||(p[a].y==p[b].y&&p[a].x<p[b].x);
}
bool cmp(point a,point b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
void update(int o){
	a[o]= a[2*o]+a[2*o+1];
}
void change(int o,int l,int r,int v,int x){
	if (l+1==r){
		a[o]+= x;
		return;
	}
	int mid= (l+r)>>1;
	if (v<mid) change(2*o,l,mid,v,x);
	else change(2*o+1,mid,r,v,x);
	update(o);
}
void find(int o,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		sum+= a[o];
		return;
	}
	int mid= (l+r)>>1;
	if (x<mid) find(2*o,l,mid,x,y);
	if (mid<y) find(2*o+1,mid,r,x,y);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	if (n%2){
		printf("0");
		return 0;
	}
	bl= 1;
	for (i= 1;i<=n;i++){
		scanf("%d%d",&p[i].x, &p[i].y);
		X[i]= Y[i]= i;
	}
	sort(X+1,X+n+1,cmpx);
	sort(Y+1,Y+n+1,cmpy);
	for (i= 1;i<=n;i= j){
		j= i+1;
		while (j<=n&&p[X[j]].x==p[X[i]].x) j++;
		if ((j-i)%2){
			bl= 0;
			break;
		}
		for (k= i;k<j;k+= 2){
			ans+= p[X[k+1]].y-p[X[k]].y;
			g[X[k]].push_back(X[k+1]);
			g[X[k+1]].push_back(X[k]);
			la++;			
			L[la]= (line){p[X[k]],p[X[k+1]]};
			q[++m]= p[X[k]];
			q[m].h= la;
		}
	}
	if (!bl){
		printf("0");
		return 0;
	}	
	for (i= 1;i<=n;i= j){
		j= i+1;
		while (j<=n&&p[Y[j]].y==p[Y[i]].y) j++;
		if ((j-i)%2){
			bl= 0;
			break;
		}
		for (k= i;k<j;k+= 2){
			ans+= p[Y[k+1]].x-p[Y[k]].x;
			g[Y[k]].push_back(Y[k+1]);
			g[Y[k+1]].push_back(Y[k]);
			q[++m]= p[Y[k]];
			q[m].h= 0;
			q[++m]= p[Y[k+1]];
			q[m].h= -1;
		}
	}
	for (i= 1;i<=n;i++){
		x= g[i].size();
		if (x!=2) bl= 0;
	}
	if (!bl){
		printf("0");
		return 0;
	}
	x= 1;
	cnt= 1;
	y= g[x][0];
	do {
		if (g[y][0]!=x){
			x= y;
			y= g[y][0];
		}else {
			x= y;
			y= g[y][1];
		}
		cnt++;		
	}while (y!=1);	
	if (cnt!=n){
		printf("0");
		return 0;
	}
	sort(q+1,q+m+1,cmp);
	l= -10010,r= 10010;
	for (i= 1;i<=m;i= j){
		j= i+1;
		while (j<=m&&q[j].x==q[i].x) j++;
		for (k= i;k<j;k++)
			if (q[k].h==-1) change(1,l,r,q[k].y,-1);
		for (k= i;k<j;k++)
			if (q[k].h>0){
				int u= q[k].h;
				find(1,l,r,L[u].a.y,L[u].b.y+1);
				if (sum) goto pn;
			}
		for (k= i;k<j;k++)
			if (q[k].h==0)
				change(1,l,r,q[k].y,1);
	}
 pn:if (sum){
		printf("0");
		return 0;
	}
	printf("%d",ans);
	return 0;
}
