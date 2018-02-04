#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 2000,oo=1e6;
int w[maxn][maxn],d[maxn],use[maxn];
int s,t,i,j,n,m,x,y,z,p;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++){
		for (j= 1;j<=n;j++)
			w[i][j]= oo*(i!=j);
		d[i]= oo;
	}
	for (i= 1;i<=m;i++){
		scanf("%d%d%d",&x, &y, &z);
		w[x][y]= min(w[x][y],z);
	}
	s= 1;t= n;d[s]= 0;
	for (i= 1;i<=n-1;i++){
		p= 0;
		for (j= 1;j<=n;j++)
			if (!use[j]&&(!p||d[p]>d[j]))
				p= j;
		for (i= 1;i<=n;i++)
			d[i]= min(d[i],d[p]+w[p][i]);
		use[p]= 1;
	}
	for (i= 1;i<=n;i++)
		printf("%d%c",d[i], i<n?' ':'\n');
	return 0;
}
