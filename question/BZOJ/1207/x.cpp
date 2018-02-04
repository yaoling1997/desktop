#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 10005;
int stack[maxn],a[maxn][3],f[maxn];
int n,m,i,j,l,r,la,ans;
int main()
{
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		f[i]= 1;
		for (j= 1;j<i;j++)
			if (abs(a[i][1]-a[j][1])+abs(a[i][2]-a[j][2])<=a[i][0]-a[j][0])
				f[i]= max(f[i],f[j]+1);
		ans= max(ans,f[i]);
	}
	printf("%d",ans);
	return 0;
}
