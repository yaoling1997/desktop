#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 2e5,maxm= 2e6+5e5,M= 17,oo= 1e8;
struct node{
	int x;
	bool operator <(const node &a)const{
		return x>a.x;
	}
};
struct point{
	int v,s,b;
};
vector<int> g[maxn];
priority_queue<node> Q[maxn];
point sta[maxn];
int L[maxm],R[maxm],left[maxm],right[maxm],Min[maxm];
int tf[maxm];
int X[maxn],Y[maxn],root[maxn],d[maxn];
int fa[maxn],par[maxn],c[maxn],size[maxn],per[maxn];
int f[maxn][20],next[maxn],XX[maxn];
int n,m,q,x,y,z,top,tot,la,i,j;
void dfs(int o,int depth){
	d[o]= depth;
	size[o]= 1;
	int len= g[o].size(),i,p= 0;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (d[v]) continue;
		dfs(v,depth+1);
		fa[v]= f[v][0]= o;
		size[o]+= size[v];
		p= size[p]>size[v]? p:v;
	}
	next[o]= p;
}
bool cmp(int a,int b){
	return d[a]<d[b];
}
void dfs1(int o){
	if (!o) return;
	par[o]= per[i];
	root[o]= top;
	X[o]= ++tot;
	Y[tot]= o;
	dfs1(next[o]);
}
void update(int o){
	Min[o]= min(Min[left[o]],Min[right[o]]);
}
void build(int &o,int l,int r,int fa){
	if (!o) o= ++top;
	tf[o]= fa;
	L[o]= l;
	R[o]= r;
	if (l+1==r){
		Min[o]= Q[Y[l]].top().x;
		XX[Y[l]]= o;
		return;
	}
	int mid= (l+r)>>1;
	build(left[o],l,mid,o);
	build(right[o],mid,r,o);
	update(o);
}
int lca(int x,int y){
	if (d[x]<d[y]) swap(x,y);
	int i;
	for (i= M;i>=0;i--)
		if (d[f[x][i]]>=d[y])
			x= f[x][i];
	if (x==y) return x;
	for (i= M;i>=0;i--)
		if (f[x][i]!=f[y][i]){
			x= f[x][i];
			y= f[y][i];
		}
	return fa[x];
}
void getMin(int o,int l,int r,point &re){
	if (l<=L[o]&&R[o]<=r){
		if (Min[o]<re.s){
			re.s= Min[o];
			re.b= 1;			
		}
		return;
	}
	int mid= (L[o]+R[o])/2;
	if (l<mid) getMin(left[o],l,r,re);
	if (mid<r) getMin(right[o],l,r,re);
}
void find(int o,int l,int r,point &re){
	if (Min[o]>re.s) return;
	if (l<=L[o]&&R[o]<=r){
		if (L[o]+1==R[o]){
			re.v= L[o];
			return;
		}
		if (Min[left[o]]==re.s)
			find(left[o],l,r,re);
		else if (Min[right[o]]==re.s)
			find(right[o],l,r,re);
		return;
	}
	int mid= (L[o]+R[o])/2;
	if (l<mid) find(left[o],l,r,re);
	if (mid<r) find(right[o],l,r,re);
}
void askMin(int x,int y,point &re){
	re.s= oo;
	if (d[x]<d[y]) swap(x,y);
	int a= lca(x,y),i;
	for (i= 1;i<=2;i++){
		while (d[a]<=d[x]){
			re.b= 0;
			if (d[par[x]]<d[a]){
				getMin(root[x],X[a],X[x]+1,re);
				if (re.b)
					find(root[x],X[a],X[x]+1,re);
				x= fa[a];
			}else {
				getMin(root[x],X[par[x]],X[x]+1,re);
				if (re.b)
					find(root[x],X[a],X[x]+1,re);
				x= fa[par[x]];
			}
		}
		if (i==1) swap(x,y);
	}
}
void del(int v){
	int o= XX[v];
	Q[v].pop();
	Min[o]= Q[v].top().x;
	o= tf[o];
	while (o){
		Min[o]= min(Min[left[o]],Min[right[o]]);
		o= tf[o];
	}
}
void get(int u,int v,int a){
	la= 0;
	point re;
	int i;
	for (i= 1;i<=a;i++){
		askMin(u,v,re);
		if (re.s==oo) break;
		sta[++la]= re;
		del(Y[re.v]);
	}
	printf("%d",la);
	for (i= 1;i<=la;i++)
		printf(" %d",sta[i].s);
	printf("\n");
	for (i= la;i>=1;i--){
		Q[Y[sta[i].v]].push((node){sta[i].s});
		int o= XX[Y[sta[i].v]];
		Min[o]= sta[i].s;
		o= tf[o];
		while (o){
			Min[o]= min(Min[left[o]],Min[right[o]]);
			o= tf[o];
		}
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &m, &q);
	for (i= 1;i<n;i++){
		scanf("%d%d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (i= 1;i<=m;i++){
		scanf("%d",&c[i]);
		Q[c[i]].push((node){i});
	}
	for (i= 1;i<=n;i++){
		per[i]= i;		
		Q[i].push((node){oo});
	}
	dfs(1,1);
	sort(per+1,per+n+1,cmp);
	for (i= 1;i<=n;i++)
		if (!root[per[i]]){
			top++;x= tot+1;
			dfs1(per[i]);
			build(root[per[i]],x,tot+1,0);
		}
	for (i= 1;i<=M;i++)
		for (j= 1;j<=n;j++)
			f[j][i]= f[f[j][i-1]][i-1];
	for (int qq= 1;qq<=q;qq++){
		scanf("%d%d%d",&x, &y, &z);
		get(x,y,z);		
	}return 0;
}
