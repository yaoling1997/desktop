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
int a[maxn],used[maxn];
int n,k,i,j,tot,A,B,C,D;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &k);
	scanf("%d%d%d%d",&A, &B, &C, &D);
	if (n==4||k<=n) printf("-1");
	else {
		a[1]= A;
		a[n]= B;
		a[2]= C;
		a[n-1]= D;
		used[A]= used[B]= used[C]= used[D]= 1;
		for (i= 3;i<n-1;i++){
			tot++;
			while (used[tot]) tot++;
			a[i]= tot;
		}
		for (i= 1;i<=n;i++)
			printf("%d%c",a[i],i<n?' ':'\n');
		printf("%d %d ",a[2],a[1]);
		for (i= 3;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d %d",a[n],a[n-1]);
	}return 0;
}