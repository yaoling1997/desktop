#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int maxn= 200,maxm= 2000,mo= 31011;
struct edge{
	int u,v,w;
};
edge edges[maxm];
multiset<int> X;
int f[maxn],stack[maxn],ST[maxn];
int n,m,ans,x,y,z,i,j,bl,cnt;
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
bool cmp(edge a,edge b){return a.w<b.w;}
int kruskal(){
	int i,cnt= 0;
	for (i= 1;i<=n;i++) f[i]= i;
	for (i= 1;i<=m;i++){
		int u= edges[i].u,v= edges[i].v;
		if (find(u)!=find(v)){
			f[f[u]]= f[v];
			X.insert(edges[i].w);
			ST[++cnt]= i;
			if (cnt==n-1) break;
		}
	}return cnt==n-1;
}
void check(int o){
	int i;
	for (i= 1;i<=n;i++)
		f[i]= i;
	for (i= 1;i<n;i++){
		if (edges[ST[i]].w==edges[stack[1]].w) continue;
		int u= edges[ST[i]].u,v= edges[ST[i]].v;
		find(u);find(v);
		f[f[u]]= f[v];
	}
	for (i= 1;i<=o;i++){
		int u= edges[stack[i]].u,v= edges[stack[i]].v;
		find(u);find(v);
		f[f[u]]= f[v];
	}
	find(1);
	for (i= 2;i<=n;i++)
		if (find(i)!=f[i-1]) return;
	cnt++;
}
void get(int o,int r,int s,int h){
	if (!s)	check(h);
	else if (o<=r){
		stack[s]= o;
		get(o+1,r,s-1,h);
		stack[s]= 0;
		get(o+1,r,s,h);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		edges[i]= (edge){x,y,z};
	}
	sort(edges+1,edges+m+1,cmp);
	bl= kruskal();
	if (!bl){
		printf("0");
		return 0;
	}
	ans= 1;
	for (i= 1;i<=m;)
		if (X.count(edges[i].w)){
			cnt= 0;x= X.count(edges[i].w);
			for (j= i;j<=m;j++)
				if (edges[j].w!=edges[i].w) break;
			get(i,j-1,x,x);
			ans= ans*cnt%mo;
			i= j;
		}else i++;
	printf("%d\n",ans);
	return 0;
}
