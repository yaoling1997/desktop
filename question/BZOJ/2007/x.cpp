#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxl= 600,maxn= maxl*maxl,oo= 1e8;
struct edge{
	int to,w;
};
vector<edge> g[maxn];
int a[maxl][maxl][4],d[maxn],vis[maxn];
int n,N,i,j,k,s,t;
void spfa(){
	int i;
	queue<int> Q;
	for (i= 1;i<=t;i++) d[i]= oo;
	d[s]= 0;Q.push(s);
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();vis[u]= 0;
		for (i= 0;i<len;i++){
			edge e= g[u][i];
			if (d[e.to]>d[u]+e.w){
				d[e.to]= d[u]+e.w;
				if (!vis[e.to]){
					vis[e.to]= 1;
					Q.push(e.to);
				}
			}
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	s= n*n+1;t= s+1;N= n+1;
	for (i= 1;i<=N;i++)
		for (j= 1;j<N;j++)
			scanf("%d",&a[i][j][0]);
	for (i= 1;i<N;i++)
		for (j= 1;j<=N;j++)
			scanf("%d",&a[i][j][1]);
	for (i= 1;i<=N;i++)
		for (j= 2;j<=N;j++)
			scanf("%d",&a[i][j][2]);
	for (i= 2;i<=N;i++)
		for (j= 1;j<=N;j++)
			scanf("%d",&a[i][j][3]);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++){
			if (i-1){
				g[(i-1)*n+j].push_back((edge){(i-2)*n+j,a[i][j][0]});
			}if (j+1<=n){
				g[(i-1)*n+j].push_back((edge){(i-1)*n+j+1,a[i][j+1][1]});
			}if (i+1<=n){
				g[(i-1)*n+j].push_back((edge){i*n+j,a[i+1][j+1][2]});				
			}if (j-1){
				g[(i-1)*n+j].push_back((edge){(i-1)*n+j-1,a[i+1][j][3]});
			}
		}
	for (i= 1;i<=n;i++){
		g[s].push_back((edge){(i-1)*n+1,a[i][1][1]});
		g[s].push_back((edge){(n-1)*n+i,a[N][i][0]});
		g[i*n].push_back((edge){t,a[i][N][1]});
		g[i].push_back((edge){t,a[1][i][0]});
	}
	spfa();
	printf("%d",d[t]);
	return 0;
}