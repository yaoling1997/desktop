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
int b[maxn];
int i,j,x,y,n,m,bl;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&y);
		for (j= 1;j<=y;j++){
			scanf("%d",&x);
			b[x]= 1;
		}
	}
	for (i= 1;i<=m;i++)
		if (!b[i]) bl= 1;
	if (bl) printf("NO");
	else printf("YES");
}
