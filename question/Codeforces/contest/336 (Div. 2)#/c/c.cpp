#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e5,oo= 1e9;
struct B{
	int a,b;
}a[maxn];
int f[maxn],sh[maxn];
int i,j,ans,n;
bool cmp(B a,B b){
	return a.a-a.b<b.a-b.b;
}
bool cmp2(int x,int y){
	return a[x].a<a[y].a;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&a[i].a, &a[i].b);
		sh[i]= i;
	}
	sort(a+1,a+n+1,cmp);
	j= 0;
	ans= oo;
	sort(sh+1,sh+n+1,cmp2);
	for (i= 1;i<=n;i++){
		while (j<i&&a[sh[j+1]].a<a[i].a-a[i].b) j++;
		f[i]= f[sh[j]]+1;
		ans= min(ans,n-f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
