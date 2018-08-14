#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 100;
int a[maxn][maxn];
int p[maxn],b[maxn];
int i,j,n,x;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for (i= 1;i<=n;i++){
		x= 0;
		memset(b,0,sizeof(b));
		for (j= 1;j<=n;j++){
			b[a[i][j]]++;
			if (b[a[i][j]]>1){
				x= a[i][j];
				break;
			}
		}
		p[i]= x;
	}
	x= n-1;
	for (i= 1;i<=n;i++)
		if (p[i]==0)
			p[i]= x++;
	for (i= 1;i<=n;i++)
		printf("%d%c",p[i],i<n?' ':'\n');
	return 0;
}
