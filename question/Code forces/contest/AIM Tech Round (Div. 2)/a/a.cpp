#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
double d,L,v1,v2,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lf%lf%lf%lf",&d, &L, &v1, &v2);
	ans= (L-d)/(v1+v2);
	printf("%.10lf",ans);
}
