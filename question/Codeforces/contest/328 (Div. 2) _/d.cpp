#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 2e5,oo= 1e8;
struct node{
	int s,v;
	bool operator <(const node a)const{
		return s>a.s||(s==a.s&&v<a.v);
	}
};
vector<int> g[maxn];
node f[maxn];
int att[maxn],b[maxn],d[maxn],vis[maxn];
int n,m,i,j,k,x,y,z,o,fa,ans,Min,cnt;
void dfs(int o,int fa){
	if (att[o]) d[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa) continue;
		dfs(v,o);
		d[o]|= d[v];
	}
}
void update(node a,node b){
	if ((ans<a.s+b.s)||(ans==a.s+b.s&&Min>min(a.v,b.v))){
		ans= a.s+b.s;
		Min= min(a.v,b.v);
	}
}
void dp(int o,int fa){
	vector<node> Q;
	Q.push_back((node){0,o});
	Q.push_back((node){0,o});	
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa||b[v]) continue;
		dp(v,o);
		Q.push_back((node){f[v].s+1,f[v].v});
	}
	sort(Q.begin(),Q.end());
	update(Q[0],Q[1]);
	f[o]= Q[0];
	Q.clear();
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<n;i++){
		scanf("%d%d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		att[x]= 1;
	}
	dfs(1,0);
	for (i= 1;i<=n;i++)
		if (!d[i]){
			b[i]= 1;
			cnt++;
		}
	o= 1;fa= 0;
	for (;;){
		if (att[o]) break;
		int len= g[o].size(),i,x= 0,u;
		for (i= 0;i<len;i++){
			int v= g[o][i];
			if (v==fa) continue;
			if (d[v]){
				x++;
				u= v;
			}
			if (x==2) break;
		}
		if (x==2) break;
		b[o]= 1;
		cnt++;
		fa= o;
		o= u;
	}
	Min= oo;ans= 0;
	dp(o,0);
	ans+= (n-cnt-ans-1)*2;
	printf("%d\n%d",Min, ans);
	return 0;
}
