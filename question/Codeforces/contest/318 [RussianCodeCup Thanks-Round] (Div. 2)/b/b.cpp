#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e3,oo= 1e9;
int L[maxn][5];
int a[maxn][maxn],d[maxn],sta[10];
int n,m,i,j,x,y,z,la,ans= oo;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		if (x>y) swap(x,y);
		L[i][1]= x;
		L[i][2]= y;
		d[x]++;
		d[y]++;
		a[x][y]= a[y][x]= 1;
	}
	for (i= 1;i<=m;i++)
		for (j= i+1;j<=m;j++){
			sta[1]= L[i][1];
			sta[2]= L[i][2];
			sta[3]= L[j][1];
			sta[4]= L[i][2];
			sort(sta+1,sta+4+1);
			la= unique(sta+1,sta+4+1)-sta-1;
			if (la==3){
				x= sta[1];
				y= sta[2];
				z= sta[3];
				if (a[x][y]&&a[y][z]&&a[z][x])
					ans= min(ans,d[x]+d[y]+d[z]-6);
			}
		}
	if (ans==oo) ans= -1;
	printf("%d\n",ans);
	return 0;
}
