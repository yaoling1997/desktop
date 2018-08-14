#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 5010;
int a[maxn][maxn];
int X[maxn],Y[maxn];
int n,m,k,x,y,z,i,j;
void go(int o){
	if (o>k) return;
	int x,y,z,i;
	scanf("%d%d%d",&x, &y, &z);
	go(o+1);	
	if (x==1){
		if (X[y]) return;
		X[y]= 1;
		for (i= 1;i<=m;i++)			
			a[y][i]= a[y][i]?a[y][i]:z;
	}else {
		if (Y[y]) return;
		Y[y]= 1;
		for (i= 1;i<=n;i++)			
			a[i][y]= a[i][y]?a[i][y]:z;		
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &m, &k);
	go(1);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			printf("%d%c",a[i][j],j<m?' ':'\n');	
}
