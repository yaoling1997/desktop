#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn= 20;
char b[maxn][maxn];
char ch;
int T,i,j,n;
int right(int x,int y){
	if (x!=1&&b[x][y]==b[x-1][y]) return 0;
	if (y!=1&&b[x][y]==b[x][y-1]) return 0;
	if (x!=n&&b[x][y]==b[x+1][y]) return 0;
	if (y!=n&&b[x][y]==b[x][y+1]) return 0;
	return 1;
}
int main()
{
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d",&n);
		for (i= 1;i<=n;i++)
			scanf("%s",b[i]+1);
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++)
				if (b[i][j]=='.')
					for (b[i][j]= 'A';b[i][j]<='Z';b[i][j]++)
						if (right(i,j)) break;
		printf("Case %d:\n",a1);
		for (i= 1;i<=n;i++)
			printf("%s\n",b[i]+1);
	}
	return 0;
}
