#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<sys/timeb.h>
#define ll long long
using namespace std;
const int maxn= 600;
int a[maxn],c[maxn*maxn];
int i,j,n,la,x;
int random(int o){
	return rand()%o;
}
int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("1.in","w",stdout);
	n= 20;
	printf("%d\n",n);
	for (i= 1;i<=n;i++)
		a[i]= random(8)+1;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			c[++la]= gcd(a[i],a[j]);
	random_shuffle(c+1,c+n*n+1);
	for (i= 1;i<=n*n;i++)
		printf("%d%c",c[i],i<n*n?' ':'\n');
	sort(a+1,a+n+1);
	for (i= n;i>0;i--)
		printf("%d%c",a[i],i>1?' ':'\n');
	return 0;
}
