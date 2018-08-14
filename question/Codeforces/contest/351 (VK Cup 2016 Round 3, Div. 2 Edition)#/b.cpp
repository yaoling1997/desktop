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
int x,y,Max,Min,n,m,i;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	Min= n;
	Max= 1;
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		if (x>y) swap(x,y);
		Max= max(Max,x);
		Min= min(Min,y);
	}
	printf("%d",max(Min-Max,0));
	return 0;
}