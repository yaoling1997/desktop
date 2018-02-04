#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#define gc getchar
using namespace std;
const double eps= 1e-8;
const int maxn= 300020,lim= 18;
vector<int> g[maxn];
vector<int> G[maxn];
int size[maxn],f[maxn][20],b[maxn],df[maxn],d[maxn];
int sta[maxn],rr[maxn],order[maxn],ans[maxn],e[maxn];
int mark[maxn],par[maxn];
int n,m,i,j,x,y,tot,top,a1,q;
void dfs(int o,int s){
	df[o]= ++tot;d[o]= s;size[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!df[v]){
			f[v][0]= o;
			dfs(v,s+1);
			size[o]+= size[v];
		}
	}
}
bool cmp(int a,int b){return df[a]<df[b];}
int LCA(int a,int b){
	if (d[b]>d[a]) swap(a,b);
	int i;
	for (i= lim;i>=0;i--)
		if (d[f[a][i]]>=d[b]) a= f[a][i];
	if (a==b) return a;
	for (i= lim;i>=0;i--)
		if (f[a][i]!=f[b][i]) 
			a= f[a][i],b= f[b][i];
	a= f[a][0];
	return a;
}
void update(int o,int v){
	if (!mark[o]) mark[o]= mark[v];
	else {
		int x= LCA(mark[o],o),y= LCA(mark[v],o),len1= d[mark[o]]+d[o]-2*d[x],len2= d[mark[v]]+d[o]-2*d[y];
		if (len1>len2||(len1==len2&&mark[v]<mark[o])) mark[o]= mark[v];
	}	
}
void pre(int o,int fa){
	par[o]= fa;
	int len= G[o].size(),i;
	mark[o]= 0;
	if (rr[o]==a1) mark[o]= o;
	for (i= 0;i<len;i++){
		int v= G[o][i];
		if (v!=fa){
			pre(v,o);
			if (rr[o]!=a1)
				update(o,v);			
		}
	}
}
int up(int o,int k){
	int x;
	while (k){
		x= log(k)/log(2)+eps;
		o= f[o][x];
		k-= 1<<x;
	}return o;
}
void get(int o,int fa){
	if (fa&&mark[fa]!=mark[o]){
		int x= mark[fa],y= mark[o],lca= LCA(x,y),len= d[x]+d[y]-2*d[lca]-1;
		int lx= d[x]-d[lca],ly= d[y]-d[lca],step= (len+1)/2,z;
		if (len&1){
			if (lx<ly){
				if (x>y) z= up(y,step);
				else z= up(y,step-1);
				ans[x]-= size[z];
				ans[y]+= size[z];
			}else {
				z= up(y,step-1);
				ans[x]-= size[z];
				ans[y]+= size[z];
			}
		}else {
			z= up(y,step);
			ans[x]-= size[z];
			ans[y]+= size[z];
		}
	}
	int len= G[o].size(),i;
	for (i= 0;i<len;i++){
		int v= G[o][i];
		if (v!=fa) get(v,o);
	}
}
int gi(){
	char c= gc();int re= 0;
	while (c<'0'||c>'9') c= gc();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= gc();
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	n= gi();
	for (i= 1;i<n;i++){
		//scanf("%d %d",&x, &y);
		x= gi(),y= gi();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,1);
	for (i= 1;i<=lim;i++)
		for (j= 1;j<=n;j++)
			f[j][i]= f[f[j][i-1]][i-1];
	q= gi();
	for (a1= 1;a1<=q;a1++){
		y= m= gi();
		for (i= 1;i<=m;i++){
			e[i]= gi();
			order[i]= e[i];
			rr[e[i]]= b[e[i]]= a1;
		}
		sort(e+1,e+m+1,cmp);
		for (i= 2;i<=m;i++){
			x= LCA(e[i],e[i-1]);
			if (b[x]!=a1){
				e[++y]= x;
				b[x]= a1;
			}
		}
		sort(e+1,e+y+1,cmp);
		for (i= 1;i<=y;i++){
			G[e[i]].clear();
			ans[e[i]]= 0;
		}
		sta[top= 1]= e[1];
		for (i= 2;i<=y;i++){
			for (;;){
				x= LCA(e[i],sta[top]);
				if (x!=sta[top]) top--;
				else {
					G[e[i]].push_back(sta[top]);
					G[sta[top]].push_back(e[i]);
					sta[++top]= e[i];
					break;
				}
			}
		}
		pre(e[1],0);
		for (i= 1;i<=y;i++)
			if (rr[e[i]]!=a1&&par[e[i]])
				update(e[i],par[e[i]]);
		ans[mark[e[1]]]= n;
		get(e[1],0);
		for (i= 1;i<=m;i++)
			printf("%d%c",ans[order[i]],i<=m?' ':'\n');
		printf("\n");
	}return 0;
}
