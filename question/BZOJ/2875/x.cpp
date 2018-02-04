#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
typedef ll matrix[3][3];
matrix A;
ll f[3];
ll m,a,c,x,n,g;
ll MUL(ll a,ll b){
	ll re= 0;
	while (b){
		if (b&1) re= (re+a)%m;
		b>>= 1;a= (a+a)%m;
	}return re;
}
void mul(matrix a,matrix b,matrix res){
	matrix c;int i,j,k;
	memset(c,0,sizeof(c));
	for (i= 1;i<=2;i++)
		for (j= 1;j<=2;j++)
			for (k= 1;k<=2;k++)
				c[i][j]= (c[i][j]+MUL(a[i][k],b[k][j]))%m;
	memcpy(res,c,sizeof(c));
}
void pow(matrix A,ll b,matrix res){
	matrix a,t;int i;
	memset(t,0,sizeof(t));
	memcpy(a,A,sizeof(a));
	for (i= 1;i<=2;i++) t[i][i]= 1;
	while (b){
		if (b&1) mul(t,a,t);
		b>>= 1;mul(a,a,a);
	}memcpy(res,t,sizeof(t));
}
void go(ll *f,matrix a,ll *res){
	ll c[3]= {0};
	int i,j;
	for (i= 1;i<=2;i++)
		for (j= 1;j<=2;j++)
			c[i]= (c[i]+MUL(f[j],a[j][i]))%m;
	memcpy(res,c,sizeof(c));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld %lld",&m, &a, &c, &x, &n, &g);
	f[1]= x;f[2]= c;
	A[1][1]= a;A[2][1]= A[2][2]= 1;
	pow(A,n,A);
	go(f,A,f);
	printf("%lld",f[1]%g);
	return 0;
}
