#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5,oo= 1e9;
char d[200][50],o[200][50],a[200][50];
int vis[200];
int T,i,j,L,n,ans,tim;
void update(int c){
	tim++;
	int i,j,k;
	int re= 0;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=L;j++)
			a[i][j]= o[i][j];
	for (j= 1;j<=L;j++)
		if (d[1][j]!=o[c][j]){
			re++;
			for (k= 1;k<=n;k++)
				a[k][j]= 49-a[k][j]+48;
		}
	if (re>=ans) return;
	vis[c]= tim;
	for (i= 2;i<=n;i++){
		int bl= 0;
		for (j= 1;j<=n;j++){
			if (vis[j]==tim) continue;
			bl= 1;
			for (k= 1;k<=L;k++)
				if (d[i][k]!=a[j][k]){
					bl= 0;
					break;
				}
			if (bl){
				vis[j]= tim;
				break;
			}
		}
		if (!bl) return;
	}
	ans= re;
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%d%d",&n, &L);
		ans= oo;
		for (i= 1;i<=n;i++)
			scanf("%s",o[i]+1);
		for (i= 1;i<=n;i++)
			scanf("%s",d[i]+1);
		for (i= 1;i<=n;i++)
			update(i);
		if (ans==oo) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}return 0;
}
