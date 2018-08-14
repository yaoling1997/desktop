#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
set<int> S;
int ans[maxn];
int n,m,i,j,k,x;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		S.insert(x);
	}
	for (i= 1;i<=m;i++){
		if (S.count(i)) continue;
		ans[++k]= i;
		m-= i;
	}
	printf("%d\n",k);
	for (i= 1;i<=k;i++)
		printf("%d%c",ans[i],i<k?' ':'\n');
	return 0;
}