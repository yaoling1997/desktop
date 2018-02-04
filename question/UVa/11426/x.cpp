#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn= 4*1e6+1;
ll phi[maxn+10],f[maxn+10],s[maxn+10];
ll ans;
int i,j,n;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	n= maxn;
	phi[1]= 1;
	for (i= 2;i<=n;i++)
		if (!phi[i])
			for (j= i;j<=n;j+= i){
				if (!phi[j]) phi[j]= j;
				phi[j]= phi[j]/i*(i-1);
			}
	for (i= 1;i<=n;i++)
		for (j= 2*i;j<=n;j+= i)
			f[j]+= phi[j/i]*i;
	s[2]= f[2];
	for (i= 3;i<=n;i++)
		s[i]= s[i-1]+f[i];
	while (true){
		scanf("%d",&n);
		if (n==0) break;
		printf("%lld\n",s[n]);
	}
	return 0;
}
