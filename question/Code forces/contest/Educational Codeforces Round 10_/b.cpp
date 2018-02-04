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
int a[maxn];
int i,n;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (i= 3;i<=n;i+= 2)
		swap(a[i],a[i-1]);
	for (i= 1;i<=n;i++)
		printf("%d%c",a[i], i<n?' ':'\n');
	return 0;
}