#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
ll X[1000],Y[1000];
ll n,m,x,y,xx,yy,base,i;
int main()
{
	scanf("%I64d%I64d",&n, &x);
	for (i= 1;i<=n;i++){
		scanf("%I64d",&X[i]);
		xx= xx*x+X[i];
	}
	scanf("%I64d%I64d",&m, &y);
	for (i= 1;i<=m;i++){
		scanf("%I64d",&Y[i]);
		yy= yy*y+Y[i];
	}
	if (xx==yy) printf("=");
	else if (xx<yy) printf("<");
	else printf(">");
	return 0;
}
