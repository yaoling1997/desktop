#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define gc getchar
using namespace std;
const int maxn= 1e5+10,maxm= 2*maxn,lim= 20;
struct query{
	int u,v,t,b;
};
struct TT{
	int p,u,v;
};
vector<int> stack[maxn];
query Q[maxn];
TT T[maxn];
ll ans[maxn],W[maxn],V[maxn];
int head[maxn],next[maxm],des[maxm],vis[maxn],f[maxn][lim+1];
int col[maxn],B[maxn],a[maxn],c[maxn],d[maxn];
ll now;
int tot,n,m,i,j,q,qt,cnt,t,u,v,x,y,z,base;
bool cmp(query a,query b){
	return B[a.u]!=B[b.u]?B[a.u]<B[b.u]:B[a.v]!=B[b.v]?B[a.v]<B[b.v]:a.t<b.t;
}
void prepare(int o,int s){
	d[o]= s;
	for (int i= head[o];i;i= next[i]){
		int v= des[i],j;
		if (v==f[o][0]) continue;
		f[v][0]= o;
		prepare(v,s+1);
		for (j= 0;j<stack[v].size();j++)
			stack[o].push_back(stack[v][j]);
		stack[v].clear();
		if (stack[o].size()>=base){
			cnt++;
			for (j= 0;j<stack[o].size();j++)
				B[stack[o][j]]= cnt;
			stack[o].clear();
		}
	}stack[o].push_back(o);
}
void vxor(int v){
	if (vis[v]){
		now-= W[c[col[v]]]*V[col[v]];
		c[col[v]]--;
		now+= W[c[col[v]]]*V[col[v]];
	}else {
		now-= W[c[col[v]]]*V[col[v]];
		c[col[v]]++;
		now+= W[c[col[v]]]*V[col[v]];		
	}vis[v]^= 1;
}
void xorpath(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	while (d[u]>d[v]){
		vxor(u);
		u= f[u][0];
	}
	while (u!=v){
		vxor(u);vxor(v);
		u= f[u][0];v= f[v][0];
	}
}
ll get(int u,int v){
	int x= u,y= v,i;
	if (d[x]<d[y]) swap(x,y);
	for (i= lim;i>=0;i--)
		if (d[f[x][i]]>=d[y]) x= f[x][i];
	for (i= lim;i>=0;i--)
		if (f[x][i]!=f[y][i])
			x= f[x][i],y= f[y][i];
	if (x!=y) x= f[x][0],y= f[y][0];
	return now-W[c[col[x]]]*V[col[x]]+W[c[col[x]]+1]*V[col[x]];
}
void goT(int o){
	int i;
	if (t<o){
		for (i= t+1;i<=o;i++){
			TT x= T[i];
			if (vis[x.p]){
				now-= W[c[x.u]]*V[x.u]+W[c[x.v]]*V[x.v];
				c[x.u]--;c[x.v]++;
				now+= W[c[x.u]]*V[x.u]+W[c[x.v]]*V[x.v];
			}col[T[i].p]= T[i].v;
		}
	}else {
		for (i= t;i>o;i--){
			TT x= T[i];
			if (vis[x.p]){
				now-= W[c[x.u]]*V[x.u]+W[c[x.v]]*V[x.v];
				c[x.u]++;c[x.v]--;
				now+= W[c[x.u]]*V[x.u]+W[c[x.v]]*V[x.v];
			}col[T[i].p]= T[i].u;
		}		
	}t= o;
}
void solve(){
	int i;now= t= 0;
	goT(Q[1].t);
	xorpath(u= Q[1].u,v= Q[1].v);
	ans[Q[1].b]= get(u,v);
	for (i= 2;i<=qt;i++){
		goT(Q[i].t);
		xorpath(u,Q[i].u);
		xorpath(v,Q[i].v);
		u= Q[i].u;v= Q[i].v;
		ans[Q[i].b]= get(u,v);
	}
}
int gi(){
	char c= gc();int re= 0;
	while (c<'0'||c>'9') c= gc();
	while ('0'<=c&&c<='9') re= re*10+c-'0',c= gc();
	return re;
}
int main()
{
	freopen("park.in","r",stdin);
	freopen("park.out","w",stdout);
	n= gi();m= gi();q= gi();
	base= pow(n,2.0/3);
	for (i= 1;i<=m;i++)
		V[i]= gi();
	for (i= 1;i<=n;i++){
		W[i]= gi();
		W[i]+= W[i-1];
	}
	for (i= 1;i<n;i++){
		x= gi();y= gi();
		next[++tot]= head[x];
		des[tot]= y;
		head[x]= tot;
		next[++tot]= head[y];
		des[tot]= x;
		head[y]= tot;
	}prepare(1,1);
	for (i= 1;i<=lim;i++)
		for (j= 1;j<=n;j++)
			f[j][i]= f[f[j][i-1]][i-1];
	for (i= 0;i<stack[1].size();i++)
		B[stack[1][i]]= cnt;
	for (i= 1;i<=n;i++){
		a[i]= gi();
		col[i]= a[i];
	}
	for (i= 1;i<=q;i++){
		x= gi();y= gi();z= gi();
		if (!x){
			T[++t]= (TT){y,a[y],z};
			a[y]= z;
		}else{
			if (B[y]>B[z]) swap(y,z);
			Q[++qt]= (query){y,z,t,qt};
		}
	}sort(Q+1,Q+qt+1,cmp);
	solve();
	for (i= 1;i<=qt;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
