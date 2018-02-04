#include<cstdio>
#include<cstdlib>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e6;
int b[maxn];
int i,n,ans;
ll p;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 2;i<=sqrt(n)+0.5;i++)
		if (!b[i]){
			p= (ll)i*i;
			while (p<=n){
				b[p]= 1;
				p+= i;
			}
		}
	b[0]= b[1]= 1;
	for (i= 2;i<=n;i++)
		if (!b[i]) ans++;
	printf("%d\n",ans);
	for (i= 2;i<=n;i++)
		if (!b[i])
			printf("%d ",i);
	return 0;
}
