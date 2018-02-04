#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 3001;
int a[maxn],f[maxn][maxn];
int n,i,oo,ans= -1e8,l,r,k,x;
int dfs(int i,int j){
	if (f[i][j]!=-oo) return f[i][j];
	int k;
	l= i+1;r= j-1;
	l-= (l>n)*n;r+= (r<1)*n;
	if (l<r){
		for (k= l;k<=r;k++)
			f[i][j]= max(f[i][j],dfs(i,k)+dfs(k,j)+a[i]+a[j]+a[k]);
	}else {
		for (k= l;k<=n;k++)
			f[i][j]= max(f[i][j],dfs(i,k)+dfs(k,j)+a[i]+a[j]+a[k]);
		for (k= 1;k<=r;k++)
			f[i][j]= max(f[i][j],dfs(i,k)+dfs(k,j)+a[i]+a[j]+a[k]);
	}
	return f[i][j];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i= 1;i<=n;i++)
		a[i+n]= a[i];
	if (n==3){printf("%d",a[1]+a[2]+a[3]);return 0;}
	memset(f,128,sizeof(f));
	oo= -f[1][1];
	for (i= 1;i<=n;i++){
		x= i+1;
		x-= (x>n)*n;
		f[i][x]= 0;
	}
	for (i= 1;i<=n;i++){
		x= i+2;
		x-= (x>n)*n;
		f[i][x]= a[i]+a[i+1]+a[i+2];
	}
	for (i= 1;i<=n;i++){
		l= i+2;r= i-2;
		l-= n*(l>n);
		r+= (r<1)*n;
		if (l<=r)
			for (k= l;k<=r;k++)
				f[i][i]= max(f[i][i],dfs(i,k)+dfs(k,i));
		else {
			for (k= l;k<=n;k++)
				f[i][i]= max(f[i][i],dfs(i,k)+dfs(k,i));
			for (k= 1;k<=r;k++)
				f[i][i]= max(f[i][i],dfs(i,k)+dfs(k,i));
		}
		ans= max(ans,f[i][i]);
	}
	printf("%d",ans);
	return 0;
}
