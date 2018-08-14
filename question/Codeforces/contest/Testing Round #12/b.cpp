#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 6e5;
struct line{
	int a,b;
	bool operator <(const line &c)const{
		return b<c.b;
	}
}L[maxn];
int ans,now,n,i;
int main()
{
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d%d",&L[i].a, &L[i].b);
	sort(L+1,L+n+1);
	now= -1;
	for (i= 1;i<=n;i++)
		if (L[i].a>now){
			ans++;
			now= L[i].b;
		}
	printf("%d",ans);
	return 0;
}
