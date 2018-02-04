#include<cstdio>
#include<cstdlib>
using namespace std;
long long m,tot,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld",&m);
	tot= 1;
	while (m>0){
		ans++;
		m-=tot;
		tot<<=1;
	}
	printf("%lld",ans);
}
