#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll maxn= 5,maxl= 2e6,mo= 1e9+7;
typedef ll matrix[maxn][maxn];
matrix A,B,C;
char s[maxl];
ll N[maxl],M[maxl],f[maxn];
ll a,b,c,d,x,y,i,t1,t2,m;
void mul(matrix a,matrix b,matrix res){
	matrix c;
	ll i,j,k;
	memset(c,0,sizeof(c));
	for (i= 1;i<=m;i++)
		for (j= 1;j<=m;j++)
			for (k= 1;k<=m;k++)
				c[i][j]= (c[i][j]+a[i][k]*b[k][j])%mo;
	memcpy(res,c,sizeof(c));
}
void pow(matrix A,ll b,matrix res){
	matrix a,t;ll i;
	memcpy(a,A,sizeof(a));
	memset(t,0,sizeof(t));
	for (i= 1;i<=m;i++)
		t[i][i]= 1;
	while (b){
		if (b&1) mul(t,a,t);
		b>>= 1;mul(a,a,a);
	}memcpy(res,t,sizeof(t));
}
void gcd(ll a,ll b){
	if (!b){
		x= 1;y= 0;
		return;
	}gcd(b,a%b);
	ll t= x;
	x= y;
	y= t-a/b*y;
}
void ksm(matrix A,ll *n,ll len,matrix res){
	matrix a,b;ll i;
	memset(a,0,sizeof(a));
	for (i= 1;i<=m;i++)
		a[i][i]= 1;
	for (i= len;i>0;i--){
		pow(a,10,a);
		pow(A,n[i],b);
		mul(a,b,a);
	}memcpy(res,a,sizeof(a));
}
void go(ll *f,matrix a,ll *res){
	ll c[maxn]= {0},i,j;
	for (i= 1;i<=m;i++)
		for (j= 1;j<=m;j++)
			c[i]= (c[i]+f[j]*a[j][i])%mo;
	memcpy(res,c,sizeof(c));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",s+1);
	t1= strlen(s+1);
	for (i= 1;i<=t1;i++)
		N[i]= s[t1-i+1]-'0';
	scanf("%s",s+1);
	t2= strlen(s+1);
	for (i= 1;i<=t2;i++)
		M[i]= s[t2-i+1]-'0';
	scanf("%lld %lld %lld %lld",&a, &b, &c, &d);
	M[1]--;
	i= 1;
	while (M[i]<0){
		M[i]+= 10;
		M[++i]--;
	}
	m= 2;
	gcd(c,mo);
	f[1]= ((1-d)*x+mo)%mo;
	f[2]= 1;
	A[1][1]= a;A[2][1]= b;A[2][2]= 1;
	B[1][1]= c;B[2][1]= d;B[2][2]= 1;
	ksm(A,M,t2,A);
	mul(B,A,A);
	ksm(A,N,t1,A);
	go(f,A,f);
	printf("%lld\n",(f[1]+mo)%mo);
	return 0;
}
