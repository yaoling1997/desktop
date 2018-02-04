#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn= 1001,oo= 1e9;
const double eps= 1e-8;
int f[maxn][maxn][10],g[maxn][maxn][10];
int ans= 2*oo,amax,amin,a,b,n,i,j,k;
int max(int a,int b,int c,int d){
	return max(max(a,b),max(c,d));
}
int min(int a,int b,int c,int d){
	return min(min(a,b),min(c,d));
}
int getint(){
	int data= 0,p= 1;
	char ch= getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')p= -1;ch= getchar();}
	do{
		data= data*10+ch-'0',ch= getchar();
	}while(ch>='0' && ch<='9');
	return data*p;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&a, &b, &n);
	for (i= 1;i<=a;i++)
		for (j= 1;j<=b;j++){
			f[i][j][0]= getint();
			//scanf("%d",&f[i][j][0]);
			g[i][j][0]= f[i][j][0];
		}
	for (i= 1;i<=7;i++)
		for (j= 1;j<=a;j++)
			for (k= 1;k<=b;k++){
				int pk= k+(1<<i-1),pj= j+(1<<i-1);
				if (j+(1<<i)-1>a || k+(1<<i)-1>b) break;
				f[j][k][i]= max(f[j][k][i-1],f[j][pk][i-1],f[pj][k][i-1],f[pj][pk][i-1]);
				g[j][k][i]= min(g[j][k][i-1],g[j][pk][i-1],g[pj][k][i-1],g[pj][pk][i-1]);
			}
	int kk= log(n)/log(2)+eps;
	for (i= 1;i<=a-n+1;i++)
		for (j= 1;j<=b-n+1;j++){
			amax= max(f[i][j][kk],f[i+n-(1<<kk)][j][kk],f[i][j+n-(1<<kk)][kk],f[i+n-(1<<kk)][j+n-(1<<kk)][kk]);
			amin= min(g[i][j][kk],g[i+n-(1<<kk)][j][kk],g[i][j+n-(1<<kk)][kk],g[i+n-(1<<kk)][j+n-(1<<kk)][kk]);
			ans= min(ans,amax-amin);
		}
	printf("%d",ans);
	return 0;
}
