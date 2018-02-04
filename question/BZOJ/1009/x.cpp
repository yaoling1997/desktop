#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 30;
typedef int matrix[maxn][maxn];
matrix a;
char s[maxn];
int f[maxn],F[maxn];
int n,m,K,i,j,k,ans;
void mul(matrix a,matrix b,matrix res){
	matrix c;
	int i,j,k;	
	memset(c,0,sizeof(c));
	for (i= 1;i<=m;i++)
		for (j= 1;j<=m;j++)
			for (k= 1;k<=m;k++)
				c[i][j]= (c[i][j]+a[i][k]*b[k][j])%K;
	memcpy(res,c,sizeof(c));
}
void pow(matrix A,int b,matrix res){
	matrix a,t;
	int i;
	memcpy(a,A,sizeof(a));
	memset(t,0,sizeof(t));
	for (i= 1;i<=m;i++)
		t[i][i]= 1;
	while (b){
		if (b&1) mul(t,a,t);
		b>>= 1;mul(a,a,a);
	}memcpy(res,t,sizeof(t));
}
void go(int *f,matrix a,int *res){
	int c[maxn]= {0},i,j;
	for (i= 1;i<=m;i++)
		for (j= 1;j<=m;j++)
			c[i]= (c[i]+f[j]*a[j][i])%K;
	memcpy(res,c,sizeof(c));
}
int ksm(int a,int b){
	int t= 1;
	while (b){
		if (b&1) t= t*a%K;
		b>>= 1;a= a*a%K;
	}return t%K;
}
void kmp(int m){
	int i,k= 0;
	F[1]= 0;
	for (i= 2;i<=m;i++){
		while (k && s[k+1]!=s[i]) k= F[k];
		if (s[k+1]==s[i]) k++;
		F[i]= k;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &m, &K);
	scanf("%s",s+1);
	if (m==0||m>n){
		printf("%d\n",ksm(10,n));
		return 0;
	}
	kmp(m);
	for (i= 0;i<m;i++)
		for (j= 0;j<=9;j++){
			k= i;
			while (k&&s[k+1]!=j+'0') k= F[k];
			if (s[k+1]==j+'0') k++;
			if (k<m) a[i+1][k+1]++;
		}
	f[1]= 1;
	pow(a,n,a);go(f,a,f);
	//for (i= 1;i<=3;i++)	go(f,a,f);
	for (i= 1;i<=m;i++)
		ans= (ans+f[i])%K;
	printf("%d\n",ans);
	return 0;
}
