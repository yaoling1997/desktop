#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e3;
int A[maxn];
int n,i,T,x,sum;
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (i= 1;i<=n;i++) scanf("%d",&A[i]);
		sum= 0;
		x= 1;
		for (i= 1;i<=n;i++){
			x= (ll)x*A[i]%9;
			sum= (sum+x)%9;
		}
		if (!sum) sum= 9;
		printf("%d\n",sum);
	}return 0;
}
