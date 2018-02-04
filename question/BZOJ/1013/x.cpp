#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn= 12;
double a[maxn][maxn];
int i,j,n;
void guass(){
	int i,j,k,r;
	for (i= 1;i<=n;i++){
		r= i;
		for (j= i+1;j<=n;j++)
			if (fabs(a[j][i])>fabs(a[r][i])) r= j;
		if (r!=i)
			for (j= i;j<=n+1;j++) swap(a[i][j],a[r][j]);
		if (!a[i][i]) return;
		for (j= i+1;j<=n;j++){
			double f= a[i][i]/a[j][i];
			for (k= i;k<=n+1;k++)
				a[j][k]= f*a[j][k]-a[i][k];
		}
	}
	for (i= n;i>=1;i--){
		for (j= i+1;j<=n;j++) a[i][n+1]-= a[j][n+1]*a[i][j];
		a[i][n+1]/= a[i][i];
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n+1;i++)
		for (j= 1;j<=n;j++)
			scanf("%lf",&a[i][j]);
	for (i= 1;i<=n;i++){
		for (j= 1;j<=n;j++)
			a[i][n+1]+= a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
		for (j= 1;j<=n;j++)
			a[i][j]= 2*(a[i][j]-a[i+1][j]);
	}
	guass();
	for (i= 1;i<=n;i++)
		printf("%.3lf%c",a[i][n+1],i<n?' ':'\n');
	return 0;
}
