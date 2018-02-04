#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 2e5,maxm= 2e6,oo= 1e8;
struct node{
	int x,y;
	bool operator <(const node &a)const{
		return x<a.x||(x==a.x&&y<a.y);
	}
	bool operator !=(const node &a)const{
		return x!=a.x||y!=a.y;
	}
};
struct edge{
	int from,to,w,b;
};
vector<edge> edges;
vector<int> g[maxn];
node l[maxm];
int b[maxm],f[maxn],vis[maxn];
int n,m,x,y,i,now= oo,a1,a2,ans;
int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}
void addedge(int x,int y,int i){
	edges.push_back((edge){x,y,1,i});
	edges.push_back((edge){y,x,-1,i});
	int m= edges.size();
	g[x].push_back(m-2);
	g[y].push_back(m-1);
}
void dfs(int o,int s){
	f[o]= s;vis[o]= 1;a1= max(a1,s);a2= min(a2,s);
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		edge e= edges[g[o][i]];
		if (b[e.b]) continue;
		b[e.b]= 1;
		if (!vis[e.to]) dfs(e.to,s+e.w);
		else {
			int x= abs(s+e.w-f[e.to]);
			if (now==oo) now= x;
			else now= gcd(now,x);
		}if (now<=2&&now) return;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		if (x==y){
			now= 1;break;
		}
		l[i]= (node){x,y};
	}
	if (now==oo){
		sort(l+1,l+m+1);
		for (i= 1;i<=m;i++)
			if (l[i]!=l[i-1])
			addedge(l[i].x,l[i].y,i);
		for (i= 1;i<=n;i++)
			if (!vis[i]){
				a1= -oo;a2= oo;		
				dfs(i,1);
				ans+= a1-a2+1;
				if (now<=2&&now) break;
			}
	}
	if (now!=oo&&now){
		if (now<=2) printf("-1 -1");
		else {
			for (i= 3;i<=now;i++)
				if (now%i==0) break;
			printf("%d %d",now, i);
		}
	}else {
		if (ans>2) printf("%d 3",ans);
		else printf("-1 -1");
	}return 0;
}
