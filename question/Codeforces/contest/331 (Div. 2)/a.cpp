#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 10;
struct point{
	int x,y;
}a[maxn];
int x,y,n,i,ans;
bool cmp(point a,point b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int main()
{
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&x, &y);
		a[i]= (point){x,y};
	}
	sort(a+1,a+n+1,cmp);
	if (n==1){
		ans= -1;
	}else if (n==2){
		if (a[1].x==a[2].x||a[1].y==a[2].y) ans= -1;
		else ans= abs(a[1].x-a[2].x)*abs(a[1].y-a[2].y);
	}else if (n==3){
		if (a[1].x==a[2].x){
			if (a[3].y==a[1].y||a[3].y==a[2].y)
				ans= abs(a[2].y-a[1].y)*abs(a[3].x-a[1].x);
			else ans= -1;
		}else if (a[1].y==a[2].y){
			if (a[3].x==a[2].x) ans= (a[2].x-a[1].x)*(a[3].y-a[2].y);
			else ans= -1;
		}else if (a[1].y==a[3].y&&a[3].x==a[2].x)
			ans= (a[3].x-a[1].x)*(a[3].y-a[2].y);
		else ans= -1;
	}else {
		if (a[1].x==a[2].x&&a[1].y==a[3].y&&a[3].x==a[4].x&&a[2].y==a[4].y) ans= (a[4].x-a[1].x)*(a[4].y-a[1].y);
		else ans= -1;
	}
	printf("%d",ans);
	return 0;
}
