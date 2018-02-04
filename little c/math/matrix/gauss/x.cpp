#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps= 1e-8;
const int maxn= 300;
double a[maxn][maxn];
int n,i,j;
bool gauss(int n){
	int i,j,r,k;double f;
	for (i= 1;i<=n;i++){
		r= i;
		for (j= i+1;j<=n;j++)
			if (fabs(a[r][i])<fabs(a[j][i])) r= j;
		if (r!=i) for (j= 1;j<=n+1;j++) swap(a[r][j],a[i][j]);
		if (fabs(a[i][i])<eps) return 0;
		for (j= i+1;j<=n;j++){
			f= a[j][i]/a[i][i];
			for (k= i;k<=n+1;k++)
				a[j][k]-= a[i][k]*f;			
		}
	}
	for (i= n;i>0;i--){
		for (j= i+1;j<=n;j++)
			a[i][n+1]-= a[j][n+1]*a[i][j];
		a[i][n+1]/= a[i][i];
	}return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n+1;j++)
			scanf("%lf",&a[i][j]);
	if (gauss(n))
		for (i= 1;i<=n;i++)
			printf("%.3lf ",a[i][n+1]);
	else printf("Oh my God!");
	return 0;
}
