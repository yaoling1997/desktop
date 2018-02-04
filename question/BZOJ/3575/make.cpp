#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<sys/timeb.h>
using namespace std;
const int maxn= 30001,sig= 10,oo= 1e8;
struct edge{
	int from,to,w,b;
};
vector<edge> edges;
vector<int> g[maxn];
int d[maxn],vis[maxn],p[maxn];
int n,m,i,j,x,y,z,L;
void addedge(int x,int y,int z,int b){
	edges.push_back((edge){x,y,z,b});
	g[x].push_back(edges.size()-1);
}
void spfa(){
	int i;
	for (i= 1;i<=n;i++) d[i]= oo;
	d[1]= 0;
	queue<int> Q;
	Q.push(1);
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size();
		Q.pop();vis[u]= 0;
		for (i= 0;i<len;i++){
			edge e= edges[g[u][i]];
			if (d[e.to]>d[u]+e.w){
				d[e.to]= d[u]+e.w;
				p[e.to]= g[u][i];
				if (!vis[e.to]){
					vis[e.to]= 1;
					Q.push(e.to);
				}
			}
		}
	}
}
int random(int o){return rand()%o;}
void print(int o){
	if (o==1) return;
	print(edges[p[o]].from);
	printf("%d ",edges[p[o]].b);
}
int main()
{
	freopen("1.in","w",stdout);
	//n= random(3)+2;m= random(5)+n;
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= random(400)+3;m= n+random(60);
	for (i= 2;i<=n;i++)
		addedge(i-1,i,random(sig),i-1);
	for (i= n;i<=m;i++)
		addedge(random(n)+1,random(n)+1,random(sig),i);
	spfa();
	int u= n;
	while (u!=1){
		L++;
		u= edges[p[u]].from;
	}
	printf("%d %d %d\n",n, m, L);
	for (i= 0;i<m;i++)
		printf("%d %d %d\n",edges[i].from,edges[i].to,edges[i].w);
	print(n);
	return 0;
}
