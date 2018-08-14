#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 3e3,maxm= 6e4,B= 5000;
ll a[maxn],b[maxm],f[5][maxm];
ld A;
double ans;
ll n,i,j,cnt,M;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (i= 1;i<=n;i++)
		for (j= i+1;j<=n;j++)
			b[a[j]-a[i]]++;
	for (i= 1;i<=B;i++)
		f[1][i]= b[i];
	for (i= 1;i<=B;i++)
		for (j= 1;j<=B;j++)
			f[2][i+j]+= f[1][i]*b[j];
	for (i= 1;i<=B;i++)
		for (j= 1;j<i;j++)
			cnt+= b[i]*f[2][j];
	M= n*(n-1)/2;
	M= M*M*M;
	A= (ld)cnt/M;
	ans= A;
	printf("%.10lf",ans);
	return 0;
}
