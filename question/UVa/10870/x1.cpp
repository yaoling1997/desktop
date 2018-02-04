#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 30;
typedef int matrix[maxn][maxn];
typedef int vec[maxn];
matrix a;
int A[maxn],F[maxn];
int d,n,mo,i;
void mul(matrix a,matrix b,matrix res){
	matrix c= {0};int i,j,k;
	for (i= 1;i<=d;i++)
		for (j= 1;j<=d;j++)
			for (k= 1;k<=d;k++)
				c[i][j]= (c[i][j]+a[i][k]*b[k][j]%mo)%mo;
	memcpy(res,c,sizeof(c));
}
void ksm(matrix a,int b,matrix res){
	matrix c= {0};
	int i;
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
	int i,j;
	for (i= 1;i<=d;i++)
		for (j= 1;j<=d;j++)
			c[i]= (c[i]+f[j]*a[j][i]%mo)%mo;
	memcpy(res,c,sizeof(c));
}
void init(){
	memset(a,0,sizeof(a));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d%d%d",&d, &n, &mo)>0){
		if (!d) break;
		init();
		for (i= 1;i<=d;i++){
			scanf("%d",&A[i]);
			A[i]%= mo;
		}
		for (i= 1;i<=d;i++){
			scanf("%d",&F[i]);
			F[i]%= mo;
		}
		for (i= 2;i<=d;i++) a[i][i-1]= 1;
		for (i= 1;i<=d;i++) a[i][d]= A[d-i+1];
		ksm(a,n-1,a);
		trans(F,a,F);
		printf("%d\n",F[1]);
	}return 0;
}
