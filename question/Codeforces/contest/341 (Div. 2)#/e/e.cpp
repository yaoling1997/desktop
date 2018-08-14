#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll mo= 1e9+7,maxn= 110;
typedef ll matrix[maxn][maxn];
typedef ll vec[maxn];
matrix a;
vec F;
ll num[maxn];
ll n,b,k,X,x,y,z,d,i,j;
void mul(matrix a,matrix b,matrix res){
	matrix c= {0};ll i,j,k;
	for (i= 1;i<=d;i++)
		for (j= 1;j<=d;j++)
			for (k= 1;k<=d;k++)
				c[i][j]= (c[i][j]+a[i][k]*b[k][j]%mo)%mo;
	memcpy(res,c,sizeof(c));
}
void ksm(matrix a,ll b,matrix res){
	matrix c= {0};
	ll i;
	for (i= 1;i<=d;i++)
		c[i][i]= 1;
	while (b){
		if (b&1) mul(c,a,c);
		b>>= 1;mul(a,a,a);
	}
	memcpy(res,c,sizeof(c));
}
void trans(vec f,matrix a,vec res){
	vec c= {0};
	ll i,j;
	for (i= 1;i<=d;i++)
		for (j= 1;j<=d;j++)
			c[i]= (c[i]+f[j]*a[j][i]%mo)%mo;
	memcpy(res,c,sizeof(c));
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n, &b, &k, &X);
	d= X;
	for (i= 1;i<=n;i++){
		scanf("%lld",&x);
		num[x]++;
	}
	F[1]= 1;
	for (i= 0;i<X;i++)
		for (j= 1;j<=9;j++)
			a[i+1][(i*10+j)%X+1]+= num[j];
	ksm(a,b,a);
	trans(F,a,F);
	printf("%lld\n",F[k+1]);
	return 0;
}
