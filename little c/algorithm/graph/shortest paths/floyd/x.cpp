#include<cstdio>
#include<cstdlib>
#include<iostream>
const int oo= 99999999;
int a[200][200];
int i,j,k,n,m,x,y,z,q;
using namespace std;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &m, &q);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			if (i!=j)
				a[i][j]= oo;
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		a[x][y]= z;
		a[y][x]= z;
	}
	for (k= 1;k<=n;k++)
		for (i= 1;i<=n;i++)
			if (i!=k)
				for (j= 1;j<=n;j++)
					if (i!=j && j!= k){
						a[i][j]= min(a[i][j],a[i][k]+a[k][j]);
						a[j][i]= a[i][j];
					}
	for (i= 1;i<=q;i++){
		scanf("%d %d",&x, &y);
		printf("%d\n",a[x][y]);
	}
	return 0;
}
