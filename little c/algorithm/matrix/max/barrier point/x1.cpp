#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 100;
int b[maxn][maxn],high[2][maxn];
int left[2][maxn],right[2][maxn];
int ll[2][maxn],rr[2][maxn];
int ans,n,m,s,i,j,x,y,p,q;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &m, &s);
	for (i= 1;i<=s;i++){
		scanf("%d %d",&x, &y);
		b[x][y]= 1;
	}
	for (i= 1;i<=m;i++)
		left[1][i]= 1,right[1][i]= m,b[1][i]= 1;
	for (i= 2;i<=n;i++){
		p= (i-1)&1;q= i&1;
		memset(ll[q],0,sizeof(ll[q]));
		memset(rr[q],0,sizeof(rr[q]));
		memset(left[q],0,sizeof(left[q]));
		memset(right[q],0,sizeof(right[q]));
		memset(high[q],0,sizeof(high[q]));		
		ll[q][0]= 1;rr[q][m+1]= m;
		for (j= 1;j<=m;j++){
			ll[q][j]= ll[q][j-1];
			if (b[i-1][j]){
				high[q][j]= 1;
				left[q][j]= 1;
			}else {
				high[q][j]= high[p][j]+1;
				left[q][j]= max(ll[p][j],left[p][j]);
			}
			if (b[i][j])
				ll[q][j]= j;
		}
		for (j= m;j>0;j--){
			rr[q][j]= rr[q][j+1];
			if (b[i-1][j])
				right[q][j]= m;
			else 
				right[q][j]= min(rr[p][j],right[p][j]);
			if (b[i][j])
				rr[q][j]= j;
		}
		for (j= 1;j<=m;j++)
			ans= max(ans,(right[q][j]-left[q][j])*high[q][j]);
	}
	printf("%d\n",ans);
	return 0;
}
