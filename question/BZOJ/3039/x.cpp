#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 2000;
int b[maxn][maxn],high[2][maxn];
int left[2][maxn],right[2][maxn];
int L[2][maxn],R[2][maxn];
char ch;
int ans,n,m,s,i,j,x,y,p,q;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d\n",&n, &m);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++){
			do scanf("%c",&ch);
			while (ch!='F'&&ch!='R');
			if (ch=='R') b[i][j]= 1;
		}	
	for (i= 1;i<=m;i++)
		left[0][i]= 0,right[0][i]= m+1,b[0][i]= 1;
	for (i= 1;i<=n;i++){
		p= (i-1)&1;q= i&1;
		memset(L[q],0,sizeof(L[q]));
		memset(R[q],0,sizeof(R[q]));
		memset(left[q],0,sizeof(left[q]));
		memset(right[q],0,sizeof(right[q]));
		memset(high[q],0,sizeof(high[q]));		
		L[q][0]= 0;R[q][m+1]= m+1;
		for (j= 1;j<=m;j++){
			L[q][j]= L[q][j-1];
			if (b[i][j]){
				L[q][j]= j;
				high[q][j]= 0;
				left[q][j]= 0;
			}else {
				high[q][j]= high[p][j]+1;
				left[q][j]= max(L[q][j],left[p][j]);
			}
		}
		for (j= m;j>0;j--){
			R[q][j]= R[q][j+1];
			if (b[i][j]){
				right[q][j]= m+1;
				R[q][j]= j;
			}
			else 
				right[q][j]= min(R[q][j],right[p][j]);
		}
		for (j= 1;j<=m;j++)
			if (right[q][j]>left[q][j])
			ans= max(ans,(right[q][j]-left[q][j]-1)*high[q][j]);
	}
	printf("%d\n",3*ans);
	return 0;
}
