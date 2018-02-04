#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
ll n,i;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=1e8;i++)
		if ((i+1)*i/2>=n) break;
	i--;
	n-= i*(i+1)/2;
	printf("%lld\n",n);
	return 0;
}
