#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 200;
int a[maxn][maxn],f[maxn][maxn][maxn],c[maxn],A[maxn],B[maxn];
int i,j,r,b,g,n,m,p,x,y,ans;
void gcd(int a,int b){
	if (!b){
		x= 1;
		y= 0;
		return;
	}
	gcd(b,a%b);
	int t= x;
	x= y;
	y= t-a/b*y;
}
int get(int *a){
	int i,j,k,z,cnt= 0;
	for (i= 1;i<=n;i++) A[i]= B[i]= 0;
	for (i= 0;i<=r;i++)
		for (j= 0;j<=b;j++)
			for (k= 0;k<=g;k++)
				f[i][j][k]= 0;
	f[0][0][0]= 1;
	for (i= 1;i<=n;i++)
		if (!B[i]){
			B[i]= 1;
			x= a[i];y= 1;
			while (x!=i){
				B[x]= 1;
				y++;
				x= a[x];
			}A[++cnt]= y;
		}
	for (i= 1;i<=cnt;i++)
		for (j= r;j>=0;j--)
			for (k= b;k>=0;k--)
				for (z= g;z>=0;z--){
					int &res= f[j][k][z]= 0;
					if (j-A[i]>=0) res+= f[j-A[i]][k][z];
					if (k-A[i]>=0) res+= f[j][k-A[i]][z];
					if (z-A[i]>=0) res+= f[j][k][z-A[i]];
				}
	return f[r][b][g];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d %d %d",&r, &b, &g, &m, &p);
	n= r+b+g;
	for (i= 1;i<=m;i++){
		int bl= 0;
		for (j= 1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if (a[i][j]!=j) bl= 1;
		}
		if (!bl) x= i;
	}
	if (x){
		for (i= x;i<=m;i++)
			for (j= 1;j<=n;j++)
				a[i][j]= a[i+1][j];
		m--;
	}
	c[0]= 1;
	for (i= 1;i<=120;i++)
		c[i]= c[i-1]*i%p;
	ans= c[n];
	gcd(c[r],p);
	ans= ans*x%p;
	gcd(c[b],p);
	ans= ans*x%p;
	gcd(c[g],p);
	ans= ans*x%p;
	for (i= 1;i<=m;i++)
		ans= (ans+get(a[i]))%p;
	gcd(m+1,p);
	ans= ans*x%p;
	printf("%d\n",(ans+p)%p);
	return 0;
}
