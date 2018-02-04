#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3e5,M= 17;
//const int maxn= 3e3,maxm= 5e3,M= 17;
struct node{
	int x,s;
};
vector<int> g[maxn];
vector<node> C[maxn];
int a[maxn][2],c[maxn],f[maxn][30],d[maxn];
int n,m,i,j,x,y,z,top,lca,ans,cnt;
void init(){
	memset(f,0,sizeof(f));
	memset(d,0,sizeof(d));
	top= 0;
	int i;
	for (i= 0;i<=n;i++){
		g[i].clear();
		C[i].clear();
		C[i].push_back((node){0,0});
	}
}
void dfs(int o,int depth){
	d[o]= depth;a[o][0]= ++top;
	int x= C[c[o]].size();
	C[c[o]].push_back((node){top,1+C[c[o]][x-1].s});
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!d[v]){
			f[v][0]= o;
			dfs(v,depth+1);
		}
	}
	a[o][1]= ++top;
	x= C[c[o]].size();
	C[c[o]].push_back((node){top,-1+C[c[o]][x-1].s});	
}
int LCA(int x,int y){
	if (d[x]<d[y]) swap(x,y);
	int i;
	for (i= M;i>=0;i--)
		if (d[f[x][i]]>=d[y])
			x= f[x][i];
	if (x==y) return x;
	for (i= M;i>=0;i--)
		if (f[x][i]!=f[y][i])
			x= f[x][i],y= f[y][i];
	return f[x][0];
}
int find(int x,int y,int z){
	int len= C[z].size(),l= 0,r= len,L,R;
	//if (len==1) return 0;
	while (l+1<r){
		int mid= (l+r)>>1;
		if (x<C[z][mid].x) r= mid;
		else l= mid;
	}
	if (C[z][l].x==x) L= l-1;
	else L= l;
	l= 0,r= len;
	while (l+1<r){
		int mid= (l+r)>>1;
		if (y<C[z][mid].x) r= mid;
		else l= mid;
	}
	R= l;
	return C[z][R].s-C[z][L].s;
}
int gi(){
	char c= getchar();int re= 0;
	while (c<'0'||c>'9') c= getchar();
	while ('0'<=c&&c<='9') re= re*10+c-'0',c= getchar();
	return re;
}
int main()
{
	while (scanf("%d%d",&n, &m)>0){
		cnt++;
		if (cnt>1) printf("\n");
		init();
		for (i= 1;i<=n;i++) c[i]= gi();
		for (i= 1;i<=n-1;i++){
			x= gi();y= gi();
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,1);
		for (i= 1;i<=M;i++)
			for (j= 1;j<=n;j++)
				f[j][i]= f[f[j][i-1]][i-1];
		for (i= 1;i<=m;i++){
			x= gi();y= gi();z= gi();
			if (d[x]<d[y]) swap(x,y);
			lca= LCA(x,y);
			if (lca==y){
				ans= find(a[y][0],a[x][0],z);
			}else {
				if (a[x][0]>a[y][0]) swap(x,y);
				ans= find(a[lca][0],a[x][0],z)-find(a[y][1],a[lca][1],z);
			}
			if (ans>0) printf("Find\n");
			else printf("NotFind\n");
		}
	}
}


