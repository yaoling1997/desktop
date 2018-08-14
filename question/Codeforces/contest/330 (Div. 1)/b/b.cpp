#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e5,oo= 2e9;
int s,f,n,r,v,i,j;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &r, &v);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&s, &f);
		double L= 0,R= 1.0*(f-s)/v;
		for (j= 1;j<=100;j++){
			double m= (L+R)/2;
			double x= m*v+2*r*fabs(sin(m*v/r/2));
			if (x>f-s) R= m;
			else L= m;
		}
		printf("%.12lf\n",L);
	}return 0;
}
