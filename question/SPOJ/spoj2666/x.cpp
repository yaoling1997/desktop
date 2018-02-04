#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e5,maxm= 1e6,M= 20,oo= 1e9;
struct edge{
	int v,w;
};
struct node{
	int v,x,t;
	bool operator <(const node a)const{
		return x<a.x;
	}
};
vector<edge> g[maxn];
priority_queue<node> Q[maxn],P;
char s[10];
int c[maxn],d[maxn],nex[maxn],par[maxn];
int X[maxn],Y[maxn],root[maxn],size[maxn],per[maxn];
int fa[maxn],cost[maxn],L[maxn],R[maxn],tim[maxn];
int timl[maxn];
int left[maxm],right[maxm],MaxL[maxm],MaxR[maxm],opt[maxm];
int x,y,z,i,j,tw,n,m,tot,top,ans,ooo;
void prepare(int o,int depth,int C){
	if (o==43429)
		ooo++;
	cost[o]= C;
	d[o]= depth;
	size[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i].v,w= g[o][i].w;
		if (v==fa[o]) continue;
		fa[v]= o;
		prepare(v,depth+1,C+w);
		size[o]+= size[v];
		if (size[v]>size[nex[o]])
			nex[o]= v;
	}
}
void mt(int &x){
	x= max(x,-oo);
}
bool cmp(int a,int b){
	return d[a]<d[b];
}
void dfs(int o){
	if (!o) return;
	par[o]= per[i];
	root[o]= top;
	X[o]= ++tot;
	Y[tot]= o;
	dfs(nex[o]);
}
int dist(int x,int y){
	if (d[x]<d[y]) swap(x,y);
	return cost[x]-cost[y];
}
void build(int &o,int l,int r){
	if (!o) o= ++top;
	L[o]= l;R[o]= r;
	if (l+1==r)
		return;	
	int m= (l+r)>>1;
	build(left[o],l,m);
	build(right[o],m,r);
}
void update(int o,int l,int r){
	int lc= left[o],rc= right[o],m= (l+r)>>1;
	MaxL[o]= max(MaxL[lc],dist(Y[l],Y[m])+MaxL[rc]);
	MaxR[o]= max(MaxR[rc],dist(Y[r-1],Y[m-1])+MaxR[lc]);
	opt[o]= max(opt[lc],opt[rc]);
	int x= MaxR[lc]+dist(Y[m-1],Y[m])+MaxL[rc];
	opt[o]= max(opt[o],x);
	mt(MaxL[o]);
	mt(MaxR[o]);
	mt(opt[o]);	
}
void getD(int o,int &D,node &u,int &bl){
	bl= 0;
	D= -oo;
	while (!Q[o].empty()){
		u= Q[o].top();
		Q[o].pop();
		if (u.t==tim[u.v]){
			D= u.x;
			bl= 1;
			break;
		}
	}
}
void get(int o,int &D,int &D2){
	node u1,u2;
	int b1,b2;
	getD(o,D,u1,b1);
	getD(o,D2,u2,b2);
	if (b1)
		Q[o].push(u1);
	if (b2)
		Q[o].push(u2);	
}
void fill(int o){
	int l= L[o],r= R[o];
	if (l+1==r){
		int D,D2;
		get(Y[l],D,D2);
		MaxL[o]= MaxR[o]= D;
		if (!c[Y[l]]){
			opt[o]= max(D+D2,D);
			MaxL[o]= MaxR[o]= max(MaxR[o],0);			
		}else 
			opt[o]= D+D2;
		mt(opt[o]);
		return;		
	}
	fill(left[o]);
	fill(right[o]);
	update(o,l,r);
}
void deal(int o){
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i].v;
		if (v==fa[o]) continue;
		deal(v);
	}
	if (o==par[o]){
		fill(root[o]);
		timl[o]++;
		P.push((node){o,opt[root[o]],timl[o]});
		tim[o]++;
		if (fa[o])
			Q[fa[o]].push((node){o,MaxL[root[o]]+dist(o,fa[o]),tim[o]});
	}
}
void change(int o,int v){
	int l= L[o],r= R[o];
	if (l+1==r){
		int D,D2;
		get(Y[l],D,D2);
		MaxL[o]= MaxR[o]= D;
		if (!c[Y[l]]){
			opt[o]= max(D+D2,D);
			MaxL[o]= MaxR[o]= max(MaxR[o],0);
		}else 
			opt[o]= D+D2;
		mt(opt[o]);		
		return;
	}
	int m= (l+r)>>1;
	if (v<m) change(left[o],v);
	else change(right[o],v);
	update(o,l,r);
}
void up(int o){
	while (o){
		change(root[o],X[o]);
		o= par[o];
		timl[o]++;
		P.push((node){o,opt[root[o]],timl[o]});		
		tim[o]++;
		if (fa[o])
			Q[fa[o]].push((node){o,MaxL[root[o]]+dist(o,fa[o]),tim[o]});
		o= fa[o];
	}
}
int main()
{
	int size = 256 << 20; // 256MB  
    char *p = (char*)malloc(size) + size;  
    __asm__("movl %0, %%esp\n" :: "r"(p));
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<n;i++){
		scanf("%d%d%d",&x, &y, &z);
		g[x].push_back((edge){y,z});
		g[y].push_back((edge){x,z});
	}tw= n;
	prepare(1,1,0);
	for (i= 1;i<=n;i++)
		per[i]= i;
	sort(per+1,per+n+1,cmp);
	for (i= 1;i<=n;i++)
		if (!root[per[i]]){
			root[per[i]]= ++top;
			x= tot+1;
			dfs(per[i]);
			build(root[per[i]],x,tot+1);
		}
	deal(1);
	scanf("%d",&m);
	for (int mm= 1;mm<=m;mm++){
		scanf("%s",s+1);
		if (s[1]=='C'){
			scanf("%d",&x);
			if (c[x]) tw++;
			else tw--;
			c[x]^= 1;
			up(x);
		}else {
			if (tw==0){
				printf("They have disappeared.\n");
			}else {
				ans= 0;
				int xx= P.size();
				while (!P.empty()){
					node u= P.top();
					if (u.t==timl[u.v]){
						ans= max(ans,u.x);
						break;
					}
					P.pop();
				}
				printf("%d\n",ans);
			}
		}
	}return 0;
}
