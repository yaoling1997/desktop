#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 30;
typedef ll matrix[maxn][maxn];
typedef ll vec[maxn];
ll a[maxn][maxn];
ll f[maxn];
ll mo,n,d,i,j,k;
void mul(matrix a,matrix b,matrix res){
	matrix c;ll i,j,k;
	memset(c,0,sizeof(c));
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			for (k= 1;k<=n;k++)
				c[i][j]= (c[i][j]+a[i][k]*b[k][j])%mo;
	memcpy(res,c,sizeof(c));
}
void ksm(matrix a,ll b,matrix res){
	matrix c;
	memset(c,0,sizeof(c));
	ll i;
	for (i= 1;i<=n;i++)
		c[i][i]= 1;
	while (b){
		if (b&1) mul(c,a,c);
		b>>= 1;mul(a,a,a);
	}
	memcpy(res,c,sizeof(c));
}
void trans(vec f,matrix a,vec res){
	vec c;
	memset(c,0,sizeof(c));
	ll i,j;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			c[i]= (c[i]+f[j]*a[j][i])%mo;
	memcpy(res,c,sizeof(c));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%lld %lld %lld",&n, &d, &mo)!=EOF){
		if (n==0 && d==0 && mo==0) return 0;
		memset(a,0,sizeof(a));
		for (i= 1;i<=n;i++)
			a[i+1][i]= 1;
		for (i= 1;i<=n;i++){
			scanf("%lld",&a[n-i+1][n]);
			a[n-i+1][n]%= mo;
		}
		for (i= 1;i<=n;i++){
			scanf("%lld",&f[i]);
			f[i]%= mo;
		}
		if (d<=n){
			printf("%lld\n",f[d]);
			continue;
		}
		ksm(a,d-n,a);
		trans(f,a,f);
		printf("%lld\n",f[n]);
	}
	return 0;
}
