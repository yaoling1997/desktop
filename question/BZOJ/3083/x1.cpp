#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001,oo= 1e9;
vector<int> g[maxn];
int a[maxn],vis[maxn];
int n,m,x,y,z,i,j,k,id,bl,ans;
void dfs(int o){
	if (o==y){
		bl= 1;
		a[o]= z;
		return;
	}
	vis[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!vis[v]){
			dfs(v);
			if (bl){
				a[o]= z;
				vis[o]= 0;
				return;
			}
		}
	}vis[o]= 0;
}
void dfs2(int o,int fa){
	if (o==x) bl= 1;
	if (bl) ans= min(ans,a[o]);
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa) continue;
		dfs2(v,o);
	}if (o==x) bl= 0;
}
int gi(){
	char c= getchar();int re= 0;
	while (c<'0'||c>'9') c= getchar();
	while ('0'<=c&&c<='9') re= re*10+c-'0',c= getchar();
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	//scanf("%d%d",&n, &m);
	n= gi();m= gi();
	for (i= 1;i<n;i++){
		x= gi();y= gi();
		//scanf("%d%d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (i= 1;i<=n;i++){
		a[i]= gi();
		//scanf("%d",&a[i]);
	}
	id= gi();
	//scanf("%d",&id);
	for (k= 1;k<=m;k++){
		x= gi();
		//scanf("%d",&x);
		if (x==1){
			x= gi();
			//scanf("%d",&x);
			id= x;
		}else if (x==2){
			x= gi();y= gi();z= gi();
			//scanf("%d%d%d",&x, &y, &z);
			bl= 0;
			dfs(x);
		}else {
			x= gi();
			//scanf("%d",&x);
			ans= oo;bl= 0;
			dfs2(id,0);
			printf("%d\n",ans);
		}
	}
	return 0;
}
