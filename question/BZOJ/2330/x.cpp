#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int maxn= 100011;
const ll oo= 1e11;
struct edge{
	int to;
	ll w;
};
edge edges[2*maxn];
vector<int> g[maxn];
int l[4*maxn],zz[maxn];
ll d[maxn];
int x,y,z,n,m,i,j,k,f,r,s,cnt,top;
ll ans,p;
void addedge(int x,int y,int z){
	edges[top++]= (edge){y,z};
	g[x].push_back(top-1);
}
int getint(){
	char c= getchar();int re= 0;
	while (c<'0'||c>'9') c= getchar();
	while (c>='0'&&c<='9'){re= re*10+c-'0';c= getchar();}
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	n= getint();m= getint();
	for (i= 1;i<=m;i++){
		x= getint();y= getint();z= getint();
		if (x==1){
			addedge(y,z,0);
			addedge(z,y,0);
		}else if (x==2){
			addedge(y,z,1);
		}else if (x==3){
			addedge(z,y,0);
		}else if (x==4){
			addedge(z,y,1);
		}else {
			addedge(y,z,0);
		}
	}
	for (i= 1;i<=n;i++)
		d[i]= 0,l[i]= i,zz[i]= 1;
	r= n;
	while (f<r){
		int u= l[++f],len= g[u].size();
		for (i= 0;i<len;i++){
			edge e= edges[g[u][i]];
			if (d[e.to]<d[u]+e.w){
				d[e.to]= d[u]+e.w;
				l[++r]= e.to;
				zz[e.to]++;
				if (zz[e.to]>n) goto pn;
			}
		}
	}
	for (i= 1;i<=n;i++)
		ans+= d[i];
	ans+= n;
	printf("%lld",ans);
	return 0;
 pn:
	printf("-1");
	return 0;
}
