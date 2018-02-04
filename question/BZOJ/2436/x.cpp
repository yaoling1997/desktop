#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int maxn= 500,oo= 1e8;
map<int,int> Map;
int B[maxn],X[maxn],Y[maxn],num[maxn][maxn];
int pre[maxn][maxn],suc[maxn][maxn],ans[maxn][maxn];
int d[maxn];
int x,y,z,i,j,k,n,Ans,t;
int f(int x,int y){
	return min(x+y,pre[i][x]+suc[j][y]+num[i][j]);
}
void init(){
	sort(B+1,B+2*n+1);
	Map[B[1]]= t= 1;
	for (i= 2;i<=2*n;i++)
		if (B[i]!=B[i-1])
			Map[B[i]]= ++t;
	for (i= 1;i<=n;i++)
		X[i]= Map[X[i]],Y[i]= Map[Y[i]];
	for (i= 1;i<=t;i++)
		for (j= i;j<=t;j++)
			for (k= 1;k<=n;k++)
				if (X[k]>=i&&Y[k]<=j) num[i][j]++;
	for (i= 1;i<=t;i++){
		for (j= num[1][i]+1;j<=t;j++)
			pre[i][j]= -oo;
		for (j= num[1][i];j>=0;j--){
			int &res= pre[i][j]= pre[i][j+1];
			for (k= 0;k<i;k++){
				res= max(res,pre[k][j]+num[k][i]);
				res= max(res,pre[k][j-num[k][i]]);
			}
		}
	}
	for (i= t;i>=1;i--){
		for (j= num[i][t]+1;j<=t;j++)
			suc[i][j]= -oo;
		for (j= num[i][t];j>=0;j--){
			int &res= suc[i][j]= suc[i][j+1];
			for (k= i+1;k<=t+1;k++){
				res= max(res,suc[k][j]+num[i][k]);
				res= max(res,suc[k][j-num[i][k]]);
			}
		}
	}
	for (i= 1;i<=t;i++)
		for (j= i;j<=t;j++){
			y= t;
			for (x= 0;x<=t;x++){
				while (y>=0&&x+y>num[i][j]+pre[i][x]+suc[j][y])
					y--;
				if (y>=0)
					ans[i][j]= max(ans[i][j],f(x,y));
			}
		}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d %d",&x, &y);
		y+= x;
		B[2*i-1]= x;
		B[2*i]= y;
		X[i]= x;Y[i]= y;
	}
	init();
	for (i= 1;i<=n;i++){
		for (j= 1;j<=X[i];j++)
			for (k= Y[i];k<=t;k++)
				d[i]= max(d[i],ans[j][k]);
		Ans= max(Ans,d[i]);
	}printf("%d\n",Ans);
	for (i= 1;i<=n;i++)
		printf("%d\n",d[i]);
	return 0;
}
