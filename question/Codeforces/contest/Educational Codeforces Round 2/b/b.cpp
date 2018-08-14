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
struct node{
	int v,h;
}b[maxn];
int a[maxn],ans[maxn];
int n,m,i,j;
bool cmp(node a,node b){
	return a.v<b.v;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (i= 1;i<=m;i++){
		scanf("%d",&b[i].v);
		b[i].h= i;
	}
	sort(b+1,b+m+1,cmp);
	j= 1;
	for (i= 1;i<=m;i++){
		while (j<=n&&a[j]<=b[i].v)
			j++;
		ans[b[i].h]= j-1;
	}
	for (i= 1;i<=m;i++)
		printf("%d%c",ans[i],i<m?' ':'\n');
	return 0;
}
