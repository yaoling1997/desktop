#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int x,y,xx,yy,i,j,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d%d",&x, &y, &xx, &yy);
	x= abs(xx-x);
	y= abs(yy-y);
	if (x>y) swap(x,y);
	ans= y;
	printf("%d",ans);
	return 0;
}
