#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define gc getchar
using namespace std;
const int maxn= 3001;
struct edge{
	int v,w;
};
vector<edge> g[maxn];
double up[maxn],down[maxn];
int stack[maxn],d[maxn],ok[maxn],vis[maxn];
double ans;
int n,m,x,y,z,i,j,k,top,bl,B;
void dfs(int o,int fa,int b){
	double re= 0;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		edge e= g[o][i];
		if (e.v!=fa){
			dfs(e.v,o,b);
			re+= down[e.v]+e.w;
		}
	}
	if (o==b) down[o]= re/len;
	else if (len>1)	down[o]= re/(len-1);
}
void Dfs(int o,int fa,int b){
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		edge e= g[o][i];
		if (e.v==fa&&o!=b){
			int x= g[fa].size()-1,y= x;
			if (ok[fa]){
				x= g[fa].size()-2;y= x;
				up[o]+= e.w+(up[fa]*2+down[fa]*x-e.w-down[o])/(x+1);
				continue;
			}
			if (fa==b) x++;
			up[o]= e.w;
			if (y) up[o]+= (up[fa]+down[fa]*x-e.w-down[o])/y;
		}
	}
	for (i= 0;i<len;i++){
		edge e= g[o][i];
		if (e.v!=fa) Dfs(e.v,o,b);
	}
}
void getcircle(int o,int fa){
	vis[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		edge e= g[o][i];
		if (e.v==fa) continue;
		if (!vis[e.v]){
			getcircle(e.v,o);
			if (bl){
				if (B){
					stack[++top]= o;
					d[top]= e.w;
					ok[o]= 1;
					if (o==B) B= 0;
				}return;
			}
		}else {
			B= e.v;
			bl= 1;
			stack[++top]= o;
			d[top]= e.w;
			ok[o]= 1;
			return;
		}
	}
}
int gi(){
	char c= gc();int re= 0;
	while (c<'0'&&c>'9') c= gc();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= gc();
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	if (n==1){
		printf("%.6lf",(double)0);
		return 0;
	}
	for (i= 1;i<=m;i++){
		//scanf("%d %d %d",&x, &y, &z);
		x= gi();y= gi();z= gi();
		g[x].push_back((edge){y,z});
		g[y].push_back((edge){x,z});
	}
	if (m==n-1){
		dfs(1,0,1);
		Dfs(1,0,1);
		ans= down[1];
		for (i= 2;i<=n;i++)
			ans+= (up[i]+down[i]*(g[i].size()-1))/g[i].size();
		printf("%.6lf\n",ans/n);
	}else {
		getcircle(1,0);
		for (i= 1;i<=top;i++){
			int u= stack[i],len= g[u].size();
			if (len==2) continue;
			for (j= 0;j<len;j++){
				edge e= g[u][j];
				if (!ok[e.v]){
					dfs(e.v,u,u);
					down[u]+= e.w+down[e.v];
				}
			}down[u]/= len-2;
		}
		for (i= 1;i<=top;i++){
			int u= stack[i],gi= g[u].size();
			for (j= 1;j<=top;j++){
				if (i==j) continue;
				double base= 1.0/2,L= 0;
				int v= stack[j],gj= g[v].size(),bl= abs(j-i)==1||abs(j-i)==top-1;
				if (gj==2){
					if (!bl) continue;
					if (i==1&&j==top){
						L= d[i+1];
						for (k= i+1;k<j;k++) base/= g[stack[k]].size()-1,L+= d[k+1];
						up[u]+= base*L;
					}else if (i==top&&j==1){
						L= d[i];
						for (k= i-1;k>j;k--)
							base/= g[stack[k]].size()-1,L+= d[k];
						up[u]+= base*L;
					}else if (i<j){
						L= d[i];
						for (k= i-1;k>0;k--)
							base/= g[stack[k]].size()-1,L+= d[k];
						for (k= top;k>j;k--)
							base/= g[stack[k]].size()-1,L+= d[k];
						up[u]+= base*L;
					}else {
						L= d[i+1];
						for (k= i+1;k<top;k++)
							base/= g[stack[k]].size()-1,L+= d[k+1];
						if (i!=top)	base/= g[stack[top]].size()-1;
						L+= d[1];
						for (k= 1;k<j;k++)
							base/= g[stack[k]].size()-1,L+= d[k+1];
						up[u]+= base*L;
					}
				}else if (i<j){
					L= d[i+1];
					for (k= i+1;k<j;k++)
						base/= g[stack[k]].size()-1,L+= d[k+1];
					//up[u]+= base*L+down[v]*(gj-2)/(bl?gj-2:gj-1);
					up[u]+= base*(gj-2)*(L+down[v])/(bl&&(j-i)>1?gj-2:gj-1);
					base= 1.0/2;L= d[i];
					for (k= i-1;k>0;k--)
						base/= g[stack[k]].size()-1,L+= d[k];
					for (k= top;k>j;k--)
						base/= g[stack[k]].size()-1,L+= d[k];
					//up[u]+= base*L+down[v]*(gj-2)/(bl?gj-2:gj-1);
					up[u]+= base*(gj-2)*(L+down[v])/(bl&&(j-i)==1?gj-2:gj-1);
				}else {
					L= d[i];
					for (k= i-1;k>j;k--)
						base/= g[stack[k]].size()-1,L+= d[k];
					//up[u]+= base*L+down[v]*(gj-2)/(bl?gj-2:gj-1);
					up[u]+= base*(gj-2)*(L+down[v])/(bl&&(i-j)>1?gj-2:gj-1);
					base= 1.0/2;L= d[i+1];
					for (k= i+1;k<top;k++)
						base/= g[stack[k]].size()-1,L+= d[k+1];
					if (i!=top)
						base/= g[stack[top]].size()-1;
					L+= d[1];
					for (k= 1;k<j;k++)
						base/= g[stack[k]].size()-1,L+= d[k+1];
					//up[u]+= base*L+down[v]*(gj-2)/(bl?gj-2:gj-1);
					up[u]+= base*(gj-2)*(L+down[v])/(bl&&(i-j)==1?gj-2:gj-1);
				}
			}
			ans+= (up[u]*2+down[u]*(gi-2))/gi;
			for (j= 0;j<gi;j++){
				edge e= g[u][j];
				if (!ok[e.v]) Dfs(e.v,u,u);
			}
		}
		for (i= 1;i<=n;i++)
			if (!ok[i]){
				int gi= g[i].size();
				ans+= (up[i]+down[i]*(gi-1))/gi;
			}
		printf("%.6lf\n",ans/n);
	}return 0;
}
