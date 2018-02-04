#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 3001;
struct point{
	int x,y;
};
point p[maxn];
int n,m,s,ans,i,j,l,r,x,y,x1,y1;
bool cmp(point a,point b){
	return a.y<b.y||(a.y==b.y&&a.x<b.x);
}
bool cmp1(point a,point b){
	return a.x<b.x;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d %d %d",&n, &m, &s);
	for (i= 1;i<=s;i++)
		scanf("%d %d",&p[i].x, &p[i].y);
	p[++s]= (point){n,1};
	p[++s]= (point){1,m};
	sort(p+1,p+s+1,cmp);
	for (i= 1;i<=s;i++){
		l= 1;r= n;
		x1= p[i].x;y1= p[i].y;
		for (j= i+1;j<=s;j++){
			x= p[j].x;y= p[j].y;
			ans= max(ans,(r-l)*(y-y1));
			if (x>l&&x<r){
				if (x<x1) l= x;
				else r= x;
			}
		}
		l= 1;r= n;
		for (j= i-1;j>0;j--){
			x= p[j].x;y= p[j].y;
			ans= max(ans,(r-l)*(y1-y));
			if (x>l&&x<r){
				if (x<=x1) l= x;
				else r= x;
			}
		}		
	}
	sort(p+1,p+s+1,cmp1);
	for (i= 1;i<=s;i++)
		ans= max(ans,(p[i].x-p[i-1].x)*(m-1));
	ans= max(ans,n-1);
	printf("%d",ans);
	return 0;
}
