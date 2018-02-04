#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 4e5;
int a[1000][1000];
ll ans;
int n,i,x,y,x0,y0,mx,my,j;
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d%d%d",&x, &y, &x0, &y0);
		mx= max(mx,x);
		mx= max(mx,x0);
		my= max(my,y);
		my= max(my,y0);				
		if (x==x0){
			if (y>y0) swap(y,y0);
			for (j= y;j<=y0;j++)
				a[x][j]= 1;
		}else {
			if (x>x0) swap(x,x0);
			for (j= x;j<=x0;j++)
				a[j][y]= 1;			
		}
	}
	for (i= 0;i<=mx;i++)
		for (j= 0;j<=my;j++)
			ans+= a[i][j];
	printf("%I64d\n",ans);
	return 0;
}
