#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn= 600;
typedef int matrix[maxn][maxn];
typedef int vec[maxn];
matrix a;
vec f;
int x,y,K,n,mo,d,i,j;
void mul(matrix a,matrix b,matrix res){
	matrix c;
	memset(c,0,sizeof(c));
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			c[1][i]= (c[1][i]+(ll)a[1][j]*b[j][i])%mo;
	for (i= 2;i<=n;i++)
		for (j= 1;j<=n;j++){
			int x= j-1;
			if (!x) x+= n;
			c[i][j]= c[i-1][x];
		}
	memcpy(res,c,sizeof(c));
}
void ksm(matrix a,int b,matrix res){
	matrix c;int i;
	memset(c,0,sizeof(c));
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
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			c[i]= (c[i]+(ll)f[j]*a[j][i])%mo;
	memcpy(res,c,sizeof(c));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d %d %d %d",&n, &mo, &d, &K)!=EOF){
		memset(a,0,sizeof(a));
		for (i= 1;i<=n;i++)
			scanf("%d",&f[i]);
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++){
				x= i;y= j;
				if (x>y) swap(x,y);
				if (y-x<=d || n-(y-x)<=d)
					a[i][j]= 1;
			}
		ksm(a,K,a);
		trans(f,a,f);
		for (i= 1;i<n;i++)
			printf("%d ",f[i]);
		printf("%d\n",f[n]);
	}
	return 0;
}
