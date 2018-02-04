#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
double eps= 1e-8;
ll n,ans,i;
int main()
{
	ans= 1;
	scanf("%I64d",&n);
	for (i= 2;i<=sqrt(n)+eps;i++)
		if (n%i==0){
			ans*= i;
			while (n%i==0) n/= i;
		}
	if (n>1) ans*= n;
	printf("%I64d",ans);
	return 0;
}
