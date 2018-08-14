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
int f[maxn];
int i,j,ans,n,cnt,p,q;
bool cmp(B a,B b){
	return a.a<b.a;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d%d",&a[i].a, &a[i].b);
	sort(a+1,a+n+1,cmp);
	ans= oo;
	for (i= n;i>0;i--){
		p= q= i;
		q--;
		cnt= n-i;
		while (q>0){
			while (q>0&&a[p].a-a[p].b<=a[q].a){
				cnt++;
				q--;
			}
			p= q;
			q--;
		}
		ans= min(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}
