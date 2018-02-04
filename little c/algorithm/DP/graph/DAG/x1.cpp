#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 3001;
int fa[maxn],fi[maxn],a[maxn];
int n,s,i,j;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &s);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	memset(fa,128,sizeof(fa));
	memset(fi,127,sizeof(fi));
	fi[0]= fa[0]= 0;
	for (i= 1;i<=s;i++)
		for (j= 1;j<=n;j++)
			if (a[j]<=i){
				fi[i]= min(fi[i],fi[i-a[j]]+1);
				fa[i]= max(fa[i],fa[i-a[j]]+1);
			}else break;
	printf("%d %d\n",fa[s],fi[s]);
	return 0;
}
