#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int maxn= 300,oo= 1e9;
struct edge{
	int from,to,w;
};
struct node{
	int u,d;
	bool operator <(const node &a)const{
		return d>a.d;
	}
};
vector<edge> g[maxn];
double val[maxn];
ll p[maxn][maxn];
int d[maxn][maxn],vis[maxn];
int x,y,z,n,m,i;
void addedge(int x,int y,int z){
	g[x].push_back((edge){x,y,z});
	g[y].push_back((edge){y,x,z});
}
void dijsktra(int s,int *d,ll *p){
	priority_queue<node> Q;	
	int i;
	for (i= 1;i<=n;i++) d[i]= oo,vis[i]= 0;
	d[s]= 0;p[s]= 1;Q.push((node){s,0});
	while(!Q.empty()){
		int u= Q.top().u,len= g[u].size();
		Q.pop();
		if (vis[u]) continue;
		vis[u]= 1;
		for (i= 0;i<len;i++){
			edge e= g[u][i];
			if (d[e.to]>d[u]+e.w){
				d[e.to]= d[u]+e.w;
				p[e.to]= p[u];
				Q.push((node){e.to,d[e.to]});
			}else if (d[e.to]==d[u]+e.w)
				p[e.to]+= p[u];
		}
	}
}
double get(int o){
	double re= 0;
	int i,j;
	for (i= 1;i<=n;i++)
		if (i!=o)
			for (j= 1;j<=n;j++)
				if (j!=o)
					if (p[i][j]&&d[i][j]==d[i][o]+d[o][j])
						re+= (double)p[i][o]*p[o][j]/p[i][j];
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		addedge(x,y,z);
	}
	for (i= 1;i<=n;i++)
		dijsktra(i,d[i],p[i]);
	for (i= 1;i<=n;i++)
		val[i]= get(i);
	for (i= 1;i<=n;i++)
		printf("%.3lf\n",val[i]);
	return 0;
}