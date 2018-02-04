#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
double l,p,q,x,y,t,m1,m2,m3,t2,t3,t4,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lf%lf%lf",&l, &p, &q);
	t= l/(p+q);
	m1= p*t;
	printf("%lf",m1);
	return 0;
}
