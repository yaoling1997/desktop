#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn= 1010,maxm= 3e6+10,oo= 1e9;
struct edge{
	int v,w;
};
struct node{
	int x,d;
	bool operator <(const node &a)const{
		return d>a.d;
	}
};
vector<edge> g[maxm];
int l[maxn][maxn][3],d[maxm],done[maxm];
int n,m,i,j,s,t,sh,ooo,Min= oo,cnt;
void addedge(int x,int y,int z){
	g[x].push_back((edge){y,z});
	g[y].push_back((edge){x,z});
}
int ID(int x,int y,int o){
	int z;
	if (o==0) z= 1;
	else z= 2;
	return (x-1)*2*m+(y-1)*2+z;
}
void dijskra(){
	priority_queue<node> Q;
	int i;
	for (i= 1;i<=t;i++) d[i]= oo;
	d[s]= 0;
	Q.push((node){s,0});
	while (!Q.empty()){
		int u= Q.top().x,len= g[u].size();
		Q.pop();
		if (done[u]) continue;
		done[u]= 1;
		for (i= 0;i<len;i++){
			int v= g[u][i].v,w= g[u][i].w;
			if (d[v]>d[u]+w){
				d[v]= d[u]+w;
				Q.push((node){v,d[v]});
			}
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	while (scanf("%d %d",&n, &m)!=EOF && n && m){
		cnt++;
		s= ID(n,m,1)+1;t= s+1;
		for (i= 1;i<=t;i++)
			g[i].clear(),done[i]= 0;
		for (i= 1;i<=n;i++)
			for (j= 1;j<m;j++)
				scanf("%d",&l[i][j][0]);
		for (i= 1;i<n;i++)
			for (j= 1;j<=m;j++)
				scanf("%d",&l[i][j][2]);
		for (i= 1;i<n;i++)
			for (j= 1;j<m;j++)
				scanf("%d",&l[i][j][1]);
		for (i= 1;i<n;i++)
			for (j= 1;j<m;j++){
				if (j!=m-1)
					addedge(ID(i,j,0),ID(i,j+1,1),l[i][j+1][2]);
				addedge(ID(i,j,0),ID(i,j,1),l[i][j][1]);
				if (i!=n-1)
					addedge(ID(i,j,1),ID(i+1,j,0),l[i+1][j][0]);
			}
		for (i= 1;i<n;i++){
			addedge(s,ID(i,1,1),l[i][1][2]);
			addedge(ID(i,m-1,0),t,l[i][m][2]);
		}
		for (i= 1;i<m;i++){
			addedge(s,ID(n-1,i,1),l[n][i][0]);
			addedge(ID(1,i,0),t,l[1][i][0]);
		}
		dijskra();
		printf("Case %d: Minimum = %d\n",cnt, d[t]);
	}
	return 0;
}
