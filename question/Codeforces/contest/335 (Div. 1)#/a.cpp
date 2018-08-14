#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5;
int f[maxn];
int n,i,x,m;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		f[x]= f[x-1]+1;
		m= max(m,f[x]);
	}
	printf("%d",n-m);
	return 0;
}
