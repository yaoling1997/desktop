#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 600;
int a[maxn],c[maxn*maxn],d[maxn*maxn];
int i,j,la,n;
int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("1.in","r",stdin);
	scanf("%d",&n);
	for (i= 1;i<=n*n;i++)
		scanf("%d",&c[i]);
	fclose(stdin);
	freopen("1.out","r",stdin);
	freopen("check.out","w",stdout);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			d[++la]= gcd(a[i],a[j]);
	sort(c+1,c+n*n+1);
	sort(d+1,d+n*n+1);
	/*for (i= 1;i<=n*n;i++)
		printf("%d%c",c[i],i<n*n?' ':'\n');
	for (i= 1;i<=n*n;i++)
	printf("%d%c",d[i],i<n*n?' ':'\n');*/
	for (i= 1;i<=n*n;i++)
		if (c[i]!=d[i]){
			printf("shit!");
			return 0;
		}
	printf("ok");
	return 0;
}
