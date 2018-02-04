#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const int maxn= 300,oo= 1e9;
struct edge{
	int from,to,w;
};
vector<edge> g[maxn];
double val[maxn];
ll p[maxn][maxn];
int a[maxn][maxn];
int x,y,z,n,m,i,j,k;
void addedge(int x,int y,int z){
	g[x].push_back((edge){x,y,z});
	g[y].push_back((edge){y,x,z});
}
double get(int o){
	double re= 0;
	int i,j;
	for (i= 1;i<=n;i++)
		if (i!=o)
			for (j= 1;j<=n;j++)
				if (j!=o)
					if (p[i][j]&&a[i][j]==a[i][o]+a[o][j])
						re+= (double)p[i][o]*p[o][j]/p[i][j];
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			if (i!=j)
				a[i][j]= oo;
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		a[x][y]= a[y][x]= z;
		p[x][y]= p[y][x]= 1;
	}
	for (i= 1;i<=n;i++) p[i][i]= 1;
	for (k= 1;k<=n;k++)
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++)
				if (i!=k&&j!=k){
					if (a[i][j]>a[i][k]+a[k][j]){
						a[i][j]= a[i][k]+a[k][j];
						p[i][j]= p[i][k]*p[k][j];
					}else if (a[i][j]==a[i][k]+a[k][j])
						p[i][j]+= p[i][k]*p[k][j];
				}
	for (i= 1;i<=n;i++)
		val[i]= get(i);
	for (i= 1;i<=n;i++)
		printf("%.3lf\n",val[i]);
	return 0;
}
