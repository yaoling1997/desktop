#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 3e4;
struct node{
	int x,v;
};
vector<int> g[maxn];
vector<node> G[maxn];
int head[maxn],next[maxn],des[maxn];
int pre[maxn],low[maxn],sta[maxn],sccno[maxn];
int d[maxn],b[maxn];
int f[maxn];
vector<int> scc[maxn];
int n,m,x,y,i,j,top,cnt,la,tim,T,ans,bl,now,bef,num,sum;
void init(){
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(head));
	memset(des,0,sizeof(head));
	memset(pre,0,sizeof(head));
	memset(low,0,sizeof(head));
	memset(sccno,0,sizeof(sccno));
	memset(d,0,sizeof(sccno));	
	memset(f,0,sizeof(f));
	memset(b,0,sizeof(b));
	top= bef=0;
	int i;
	for (i= 1;i<=cnt;i++){
		scc[i].clear();
		g[i].clear();
		G[i].clear();
	}
	cnt= 0;
	ans= 0;
	num= 0;
	sum= 0;
}
void dfs(int o){
	pre[o]= low[o]= ++tim;
	sta[++la]= o;
	for (int p= head[o];p;p= next[p]){
		int v= des[p];
		if (!pre[v]){
			dfs(v);
			low[o]= min(low[o],low[v]);
		}else if (!sccno[v])
			low[o]= min(low[o],pre[v]);
	}
	if (low[o]==pre[o]){
		cnt++;
		for (;;){
			int x= sta[la--];
			scc[cnt].push_back(x);
			sccno[x]= cnt;
			if (x==o) break;
		}
		d[cnt]= scc[cnt].size();
		if (d[cnt]==2) num++;
	}
}
void ok(int o){
	if (d[o]==2){
		G[o].push_back((node){i,now});
		return;
	}
	if (d[o]>2){
		return;
	}
	now+= d[o];	
	ok(g[o][0]);
}
bool cmp(node a,node b){
	return a.v>b.v;
}
void deal(int o){
	if (d[o]==2) return;
	b[o]= 1;
	deal(g[o][0]);
}
int get(int o){
	queue<node> Q;
	int x= scc[o][0],y= scc[o][1],i,rx= 0,ry= 0;
	for (i= 1;i<=n;i++){
		if (i==y) continue;
		if (d[sccno[i]]==1)
			if (des[head[i]]==x){
				Q.push((node){i,1});
				rx= 1;
			}
	}
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		for (i= 1;i<=n;i++)
			if (d[sccno[i]]==1){
				if (des[head[i]]==u.x){
					rx= u.v+1;
					Q.push((node){i,rx});
				}
			}
	}
	for (i= 1;i<=n;i++){
		if (i==x) continue;
		if (d[sccno[i]]==1)
			if (des[head[i]]==y){
				Q.push((node){i,1});
				ry= 1;
			}
	}
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		for (i= 1;i<=n;i++)
			if (d[sccno[i]]==1){
				if (des[head[i]]==u.x){
					ry= u.v+1;
					Q.push((node){i,ry});
				}
			}
	}
	return 2+rx+ry;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%d",&n);
		init();
		for (i= 1;i<=n;i++){
			scanf("%d",&x);
			top++;
			des[top]= x;
			next[top]= head[i];
			head[i]= top;
		}
		for (i= 1;i<=n;i++)
			if (!pre[i]) dfs(i);
		for (i= 1;i<=cnt;i++){
			int len= scc[i].size();
			ans= max(ans,len);
			if (d[i]==2){
				now= get(i);
				sum+= now;
			}
		}
		ans= max(ans,sum);
		printf("%d\n",ans);
	}
	return 0;
}
