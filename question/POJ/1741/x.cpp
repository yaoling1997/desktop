#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<ctime>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e4,oo= 1e9;
struct edge{
	int v,w;
};
vector<edge> g[maxn];
vector<int> M,V[maxn];
int b[maxn],size[maxn];
int n,m,i,j,x,y,z,ans,K;
void init(){
	int i;
	for (i= 1;i<=n;i++)
		g[i].clear();
	memset(b,0,sizeof(b));
	ans= 0;
}
void getTot(int o,int fa,int &tot){
	tot++;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i].v;
		if (v==fa||b[v]) continue;
		getTot(v,o,tot);
	}
}
void barycenter(int o,int fa,int &bc,int &s,int tot){
	size[o]= 1;
	int len= g[o].size(),i,mx= 0;
	for (i= 0;i<len;i++){
		int v= g[o][i].v;
		if (b[v]||v==fa) continue;
		barycenter(v,o,bc,s,tot);
		mx= max(mx,size[v]);
		size[o]+= size[v];
	}
	mx= max(mx,tot-size[o]);
	if (mx<s){
		bc= o;
		s= mx;
	}
}
void prepare(int o,int fa,int s,int r){
	M.push_back(s);
	V[r].push_back(s);
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i].v,w= g[o][i].w;
		if (b[v]||v==fa) continue;
		prepare(v,o,s+w,r);
	}
}
int count(int x,int i){
	int j= upper_bound(M.begin(),M.end(),K-x)-M.begin();
	int k= upper_bound(V[i].begin(),V[i].end(),K-x)-V[i].begin();
	return j-k;
}
void update(int o){
	int len= g[o].size(),i,sum= 0;
	M.clear();	
	for (i= 0;i<len;i++){
		V[i].clear();
		int v= g[o][i].v,w= g[o][i].w;
		if (b[v]) continue;
		prepare(v,o,w,i);
		sort(V[i].begin(),V[i].end());
	}
	sort(M.begin(),M.end());
	for (i= 0;i<len;i++){
		int L= V[i].size(),j;
		for (j= 0;j<L;j++){
			int x= V[i][j];
			if (x<=K) sum+= 2;
			sum+= count(x,i);
		}
	}
	ans+= sum/2;
}
void get(int o){
	int tot= 0,num= oo;
	getTot(o,0,tot);
	barycenter(o,0,o,num,tot);
	b[o]= 1;
	update(o);
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i].v;
		if (b[v]) continue;
		get(v);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d%d",&n, &K)>0){
		if (!n&&!K) break;
		init();
		for (i= 1;i<n;i++){
			scanf("%d%d%d",&x, &y, &z);
			g[x].push_back((edge){y,z});
			g[y].push_back((edge){x,z});			
		}
		get(1);
		printf("%d\n",ans);
	}
	return 0;
}
