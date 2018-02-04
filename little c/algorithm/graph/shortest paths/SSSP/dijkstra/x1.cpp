#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 3001,oo= 1e8;
struct node{
	int v,w;
	bool operator <(const node&a)const{
		return w>a.w;
	}
};
struct edge{
	int to,w;
};
priority_queue<node> Q;
vector<edge> edges;
vector<int> g[maxn];
int b[maxn],d[maxn];
int n,m,s,i,j,x,y,z;
void addedge(int x,int y,int z){
	edges.push_back((edge){y,z});
	g[x].push_back(edges.size()-1);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &m, &s);
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		addedge(x,y,z);
	}
	for (i= 1;i<=n;i++)
		d[i]= oo;
	d[s]= 0;
	Q.push((node){s,0});
	while (!Q.empty()){
		int u= Q.top().v,len= g[u].size();Q.pop();
		if (b[u]) continue;
		b[u]= 1;
		for (i= 0;i<len;i++){
			edge e= edges[g[u][i]];
			if (d[u]+e.w<d[e.to]){
				d[e.to]= d[u]+e.w;
				Q.push((node){e.to,d[e.to]});
			}
		}
	}
	for (i= 1;i<=n;i++)
		printf("%d%c",d[i], i<n?' ':'\n');
	return 0;
}
