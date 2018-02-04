#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e3;
int a[maxn];
int T,n,i,x;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%d",&n);
		x= 0;
		for (i= 0;i<n;i++){
			scanf("%d",&a[i]);
			if (a[i]<=i) x++;
		}
		if (abs(x-472)<abs(x-500)) printf("BAD\n");
		else printf("GOOD\n");
	}return 0;
}
