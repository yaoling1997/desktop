#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e3,oo= 1e9;
int d1,d2,d3,ans;
int main()
{
	scanf("%d%d%d",&d1, &d2, &d3);
	ans= 2*(d1+d2);
	ans= min(ans,d1+d3+d2);
	ans= min(ans,(min(d1,d2)+d3)*2);
	printf("%d",ans);
	return 0;
}
