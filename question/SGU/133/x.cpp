#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e4;
struct node{
	int a,b;
}a[maxn];
bool cmp(node a,node b){
	return a.a<b.a||(a.a==b.a&&a.b<b.b);
}
int n,i,ans,M;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d%d",&a[i].a, &a[i].b);
	sort(a+1,a+n+1,cmp);
	M= -1;
	for (i= 1;i<=n;i++)
		if (a[i].b<M) ans++;
		else M= a[i].b;
	printf("%d",ans);
	return 0;
}
