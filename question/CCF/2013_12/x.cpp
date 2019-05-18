#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxm= 1e5;
int c[maxm];
int n,i,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	ans= 0;
	for (i= 1;i<=n;i++){
		int x;
		scanf("%d",&x);
		c[x]++;
		if (c[ans]<c[x])
			ans= x;
		else if ((c[ans]==c[x])&&(ans>x))
			ans= x;
	}
	printf("%d",ans);
	return 0;
}
