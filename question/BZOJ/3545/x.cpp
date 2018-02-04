#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 4000001,maxm= 6e5,oo= 2e9;
struct edge{
	int x,y,w;
};
vector<edge> g[maxn];
edge l[maxm];
int h[maxm],f[maxm],par[maxm],w[maxm],size[maxn],X[maxm],Y[maxm];
int left[maxn],right[maxn],a[maxm],RR[maxm],vis[maxm];
int tot,top,x,y,z,n,m,q,s,ans,i,L= oo,R= -oo;
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
bool cmp(edge a,edge b){return a.w<b.w;}
void dfs(int o,int fa){
	X[o]= ++tot;Y[tot]= o;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i].y;
		if (v!=fa)
			dfs(v,o);		
	}
	RR[o]= X[o];
	if (len)
		RR[o]= RR[g[o][len-1].y];
}
void update(int o,int l,int r,int w){
	size[++top]= size[o]+w;
	left[top]= l;
	right[top]= r;
}
int change(int o,int l,int r,int x,int w){
	if (l+1==r){
		update(o,0,0,w);
		return top;
	}
	int mid= (l+r)>>1,re;
	if (x<mid){
		re= change(left[o],l,mid,x,w);
		update(o,re,right[o],w);
	}else {
		re= change(right[o],mid,r,x,w);
		update(o,left[o],re,w);
	}return top;
}
void kruskal(){
	int i,x,y;
	sort(l+1,l+m+1,cmp);
	for (i= 1;i<=m;i++){
		x= l[i].x,y= l[i].y;
		if ((x= find(x))!=(y= find(y))){
			if (size[x]<size[y]) swap(x,y);
			size[x]+= size[y];
			f[y]= x;
			par[y]= x;
			w[y]= l[i].w;
			g[x].push_back((edge){x,y,l[i].w});
		}
	}
	for (i= 1;i<=n;i++) find(i);
	for (i= 1;i<=n;i++)
		if (!vis[f[i]]){
			vis[f[i]]= 1;
			dfs(f[i],-1);
		}
	memset(size,0,sizeof(size));
	for (i= 1;i<=n;i++)
		a[i]= change(a[i-1],L,R,h[Y[i]],1);
}
int fen2(int v,int x){
	int l= -1,r= g[v].size();
	while (l+1<r){
		int mid= (l+r)>>1;
		if (g[v][mid].w<=x) l= mid;
		else r= mid;
	}return l;
}
int ask(int x,int y,int K){
	--x;
	y= a[y];x= a[x];
	K= size[y]-size[x]-K+1;
	if (K<=0) return -1;
	int l= L,r= R;
	while (l+1<r){
		int mid= (l+r)>>1;
		if (size[left[y]]-size[left[x]]<K){
			K-= size[left[y]]-size[left[x]];
			x= right[x];y= right[y];
			l= mid;
		}else {
			x= left[x];y= left[y];
			r= mid;
		}
	}return l;
}
int get(int v,int x,int K){
	while (par[v]&&w[v]<=x) v= par[v];
	int i= fen2(v,x),zz= i<0?X[v]:RR[g[v][i].y];
	return ask(X[v],zz,K);
}
int gi(){
	char c= getchar();int re= 0,p= 1;
	while ((c<'0'||c>'9')&&c!='-') c= getchar();
	if (c=='-') p= -1,c= getchar();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= getchar();
	return re*p;
}
int main()
{
	n= gi();m= gi();q= gi();
	for (i= 1;i<=n;i++){
		h[i]= gi();
		size[i]= 1;f[i]= i;
		L= min(L,h[i]);R= max(R,h[i]);
	}
	L--;R++;
	for (i= 1;i<=m;i++){
		x= gi();y= gi();z= gi();
		l[i]= (edge){x,y,z};
	}
	kruskal();
	for (int a1= 1;a1<=q;a1++){
		x= gi();y= gi();z= gi();
		//if (ans!=-1){x^= ans;y^= ans;z^= ans;}
		ans= get(x,y,z);
		printf("%d\n",ans);
	}return 0;
}
