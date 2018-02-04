#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 10000;
struct node{
	int b,j;
};
node a[maxn];
int i,n,ans,m,cnt;
bool cmp(node a,node b){
	return a.j>b.j;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while(scanf("%d",&n)!=EOF){
		cnt++;
		if (!n) break;
		for (i= 1;i<=n;i++)
			scanf("%d %d",&a[i].b, &a[i].j);
		sort(a+1,a+n+1,cmp);
		ans= m= 0;
		for (i= 1;i<=n;i++)
			m+= a[i].b,ans= max(ans,m+a[i].j);
		printf("Case %d: %d\n",cnt, ans);
	}
	return 0;
}
