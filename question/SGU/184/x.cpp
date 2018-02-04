#include<cstdio>
#include<algorithm>
using namespace std;
int x1,x2,x3,y1,y2,y3,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d%d",&x1, &x2, &x3);
	scanf("%d%d%d",&y1, &y2, &y3);
	ans= x1/y1;
	ans= min(ans,x2/y2);
	ans= min(ans,x3/y3);
	printf("%d",ans);
	return 0;
}
