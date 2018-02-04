#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define ll long long
const int maxn= 2e4+10,maxm= 1e6,oo= 1e6;
struct edge{
	int from,to,cap,flow;
};
edge edges[maxm];
queue<int> Q;
int d[maxn],cur[maxn],vis[maxn],num[maxn],p[maxn];
int next[maxm],g[maxn];
int x,y,z,n,m,i,s,t,flow,es;
void addedge(int from,int to,int cap){
	edges[es++]= (edge){from,to,cap,0};
	edges[es++]= (edge){to,from,0,0};
	next[es-2]= g[from];
	g[from]= es-2;
	next[es-1]= g[to];
	g[to]= es-1;
}
void bfs(){
	for (int i= 1;i<=n;i++)	d[i]= t;
	d[t]= 0;
	memset(vis,0,sizeof(vis));
	vis[t]= 1;
	Q.push(t);
	while (!Q.empty()){
		int u= Q.front(),i;
		Q.pop();
		for (i= g[u];i!=-1;i= next[i]){
			if ((i&1)==0) continue;
			edge e= edges[i];
			if (!vis[e.to]){
				vis[e.to]= 1;
				d[e.to]= d[u]+1;
				Q.push(e.to);
			}
		}
	}
}
int augment(){
	int x= t,a= oo;
	while (x!=s){
		edge &e= edges[p[x]];
		a= min(a,e.cap-e.flow);
		x= edges[p[x]].from;
	}
	x= t;
	while (x!=s){
		edges[p[x]].flow+= a;
		edges[p[x]^1].flow-= a;
		x= edges[p[x]].from;
	}return a;
}
int maxflow(int s,int t){
	int flow= 0,n= t,i;
	bfs();
	memset(num,0,sizeof(num));
	for (i= 1;i<=n;i++){
		cur[i]= g[i];
		num[d[i]]++;
	}
	int x= s;
	while (d[s]<n){
		if (x==t){
			flow+= augment();
			x= s;
		}
		int ok= 0;
		for (i= cur[x];i!=-1;i= next[i]){
			edge &e= edges[i];
			if (e.cap>e.flow&&d[x]==d[e.to]+1){
				ok= 1;
				p[e.to]= i;
				cur[x]= i;
				x= e.to;
				break;
			}
		}
		if (!ok){
			int m= n-1;
			for (i= g[x];i!=-1;i= next[i]){
				edge &e= edges[i];
				if (e.cap>e.flow) m= min(m,d[e.to]);
			}
			if (--num[d[x]]==0) break;
			num[d[x]= m+1]++;
			cur[x]= g[x];
			if (x!=s) x= edges[p[x]].from;
		}
	}return flow;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d%d%d",&n, &m, &s, &t);
	for (i= 1;i<=n;i++)	g[i]= -1;
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		addedge(x,y,z);
	}
	flow= maxflow(s,t);
	printf("%d\n",flow);
  return 0;
}
