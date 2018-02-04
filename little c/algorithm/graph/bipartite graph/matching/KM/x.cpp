#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001,oo= 1e8;
struct edge{
	int v,w;
};
vector<edge> g[maxn];
int lx[maxn],ly[maxn],S[maxn],T[maxn],d[maxn];
int n,m,x,y,z,i,j,ans;
bool match(int o){
	S[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i].v,w= g[o][i].w;
		if (lx[o]+ly[v]==w && !T[v]){
			T[v]= 1;
			if (!d[v] || match(d[v])){
				d[v]= o;
				return 1;
			}
		}
	}return 0;
}
void update(){
	int i,j,a= oo;
	for (i= 1;i<=n;i++)
		if (S[i]){
			int len= g[i].size();
			for (j= 0;j<len;j++){
				int v= g[i][j].v;
				if (!T[v])
					a= min(a,lx[i]+ly[v]-g[i][j].w);
			}
		}
	for (i= 1;i<=n;i++){
		if (S[i]) lx[i]-= a;
		if (T[i]) ly[i]+= a;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		g[x].push_back((edge){y,z});
	}
	for (i= 1;i<=n;i++){
		d[i]= ly[i]= 0;
		lx[i]= -oo;int len= g[i].size();
		for (j= 0;j<len;j++)
			lx[i]= max(lx[i],g[i][j].w);
	}
	for (i= 1;i<=n;i++)
		for (;;){
			for (j= 1;j<=n;j++) S[j]= T[j]= 0;
			if (match(i)) break;
			else update();
		}
	for (i= 1;i<=n;i++)
		ans+= lx[i]+ly[i];
	printf("%d",ans);
	return 0;
}
