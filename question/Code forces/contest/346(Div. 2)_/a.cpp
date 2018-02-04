#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int n,a,b,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &a, &b);
	a+= b;
	while (a>n) a-=n;
	while (a<=0) a+= n;
	printf("%d\n",a);
	return 0;
}