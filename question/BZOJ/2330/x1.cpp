#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define gi getint()
#define gc getchar()
using namespace std;
const int maxn= 200101,maxm= 200101;
int head1[maxn],next1[maxm],des1[maxm],w1[maxm],f[maxn];
int head[maxn],next[maxm],des[maxm],w[maxm],vis[maxn],d[maxn][2];
int pre[maxn],low[maxn],stack[maxn],b[maxn],sccno[maxn],scc[maxn];
int x,y,z,n,i,k,tot,la,time,bl,cnt,top;
ll ans;
void addedge(int x,int y,int z){
	next[++top]= head[x];
	head[x]= top;
	des[top]= y;
	w[top]= z;
}
void addedge1(int x,int y,int z){
	next1[++top]= head1[x];
	head1[x]= top;
	des1[top]= y;
	w1[top]= z;
}
void dfs(int o){
	pre[o]= low[o]= ++time;
	stack[++la]= o;int p= head1[o];
	while (p){
		int v= des1[p];
		if (!w1[p]){
			if (!pre[v]){
				dfs(v);
				low[o]= min(low[o],low[v]);
			}else if (!sccno[v])
				low[o]= min(low[o],pre[v]);
		}
		p= next1[p];
	}
	if (low[o]==pre[o]){
		cnt++;
		while (true){
			scc[cnt]++;
			int x= stack[la--];
			sccno[x]= cnt;
			if (x==o) break;
		}
	}
}
int dfs2(int o){
	if (f[o]) return f[o];
	f[o]= 1;int p= head[o];
	while (p){
		int v= des[p];
		f[o]= max(f[o],dfs2(v)+w[p]);
		p= next[p];
	}
	return f[o];
}
int gi{
	char c= gc;int re= 0;
	while (c<'0'||c>'9') c= gc;
	while (c>='0'&&c<='9') re= re*10+c-'0',c= gc;
	return re;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	n= gi;k= gi;
	for (i= 1;i<=k;i++){
		x= gi;y= gi;z= gi;
		if (x==1){
			addedge1(y,z,0);
			addedge1(z,y,0);
		}else if (x==2){
			addedge1(z,y,1);
		}else if (x==3){
			addedge1(y,z,0);
		}else if (x==4){
			addedge1(y,z,1);
		}else if (x==5){
			addedge1(z,y,0);
		}
	}
	bl= 1;
	for (i= 1;i<=n;i++)
		if (!pre[i])
			dfs(i);
	top= 0;
	for (i= 1;i<=n;i++){
		int p= head1[i];
		while (p){
			int v= des1[p];
			if (sccno[i]!=sccno[v])
				addedge(sccno[i],sccno[v],w1[p]);
			else if (w1[p]){bl= 0;goto pn;}
			p= next1[p];
		}
	}
 pn:
	if (!bl){printf("-1");return 0;}
	for (i= 1;i<=cnt;i++){
		if (!f[i])
			dfs2(i);
		ans+= (ll)f[i]*scc[i];
	}
	printf("%lld",ans);
	return 0;
}
