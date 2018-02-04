#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 1e6,oo= 1e8;
int a[maxn];
int i,j,ans,T,Max,x,n;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d",&n);scanf("%d",&Max);
		ans= -oo;
		for (i= 2;i<=n;i++){
			scanf("%d",&x);
			ans= max(ans,Max-x);
			Max= max(Max,x);
		}printf("%d\n",ans);
	}return 0;
}
