#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const double oo= 1e8,eps= 1e-8;
const int maxn= 6001;
struct edge{
	int from,to;
	double w;
};
double h[maxn];
struct node{
	int v;
	double g;
	bool operator <(const node &a)const{
		return g+h[v]>a.g+h[a.v];
	}
};
vector<edge> edges;
vector<int> g[maxn];
int vis[maxn];
double E,z;
int x,y,n,m,i,ans;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
void addedge(int x,int y,double w){
	edges.push_back((edge){x,y,w});
	edges.push_back((edge){y,x,w});
	int m= edges.size();
	g[x].push_back(m-2);
	g[y].push_back(m-1);
}
void spfa(int s,int t){
	queue<int> Q;
	int i;
	for (i= 1;i<=n;i++) h[i]= oo;
	h[s]= 0;
	Q.push(s);
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();vis[u]= 0;
		for (i= 0;i<len;i++)
			if (g[u][i]&1){
				edge e= edges[g[u][i]];
				if (h[e.to]>h[u]+e.w){
					h[e.to]= h[u]+e.w;
					if (!vis[e.to]){
						vis[e.to]= 1;
						Q.push(e.to);
					}
				}
			}
	}
}
void solve(){
	priority_queue<node> Q;
	Q.push((node){1,0});
	while (!Q.empty()){
		node u= Q.top();Q.pop();
		if (u.v==n){
			if (dcmp(E-u.g)>=0) E-= u.g,ans++;
			else break;
		}else {
			int len= g[u.v].size(),i;
			for (i= 0;i<len;i++)
				if ((g[u.v][i]&1)==0){
					edge e= edges[g[u.v][i]];
					Q.push((node){e.to,u.g+e.w});
				}
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %lf",&n, &m, &E);
	for (i= 1;i<=m;i++){
		scanf("%d %d %lf",&x, &y, &z);
		addedge(x,y,z);
	}
	spfa(n,1);
	solve();
	printf("%d\n",ans);
	return 0;
}
