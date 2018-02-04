#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 3001;
int phi[maxn];
int i,j,n;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 2;i<=n;i++) phi[i]= 0;
	phi[1]= 1;
	for (i= 2;i<=n;i++)
		if (!phi[i])
			for (j= i;j<=n;j+= i){
				if (!phi[j]) phi[j]= j;
				phi[j]= phi[j]/i*(i-1);
			}
	for (i= 1;i<=n;i++)
		printf("%d: %d\n",i, phi[i]);
	return 0;
}
