#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 1010;
int p[maxn][maxn];
double tot[maxn],ans[maxn];
int done[maxn];
int n,m,i,j,k,q;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		for (j= 1;j<=n;j++)
			scanf("%d",&p[i][j]);
		ans[i]= 1/0.;
		tot[i]= 1;
	}
	ans[n]= 0;
	for (i= 1;i<n;i++){
		q= -1;
		for (j= 1;j<=n;j++){
			if (done[j]) continue;
			if (q==-1||ans[q]>ans[j])
				q= j;
		}
		if (q==-1) break;
		done[q]= 1;
		for (j= 1;j<=n;j++){
			if (done[j]) continue;
			ans[j]= ans[j]==1/0.?1:ans[j]*(1-tot[j]);
			ans[j]+= ans[q]*tot[j]*p[j][q]/100.;
			tot[j]*= 1-p[j][q]/100.;
			ans[j]/= 1-tot[j];
		}
	}
	printf("%.9lf",ans[1]);
	return 0;
}
