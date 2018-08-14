#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 4e5+10,maxm=2*maxn;
vector<int> g[maxn];
int root[61],s[61][maxm],left[61][maxm],right[61][maxm];
int z[61][maxm];
int c[maxn],a[maxn][2],Y[maxm];
int x,y,n,m,i,j,ans,tot,L,R,top;
void dfs(int o,int fa){
	a[o][0]= ++tot;
	Y[tot]= o;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (v==fa) continue;
		dfs(v,o);
	}
	a[o][1]= ++tot;
	Y[tot]= o;
}
void update(int o,int i){
	int l= left[i][o],r= right[i][o];
	int x= z[i][l],y= z[i][r];
	if (x==-1) x= s[i][l];
	if (y==-1) y= s[i][r];
	s[i][o]= x|y;
}
void pushdown(int o,int i){
	if (z[i][o]==-1) return;
	int l= left[i][o],r= right[i][o];
	z[i][l]= z[i][o];
	z[i][r]= z[i][o];
	z[i][o]= -1;
}
void build(int &o,int l,int r,int i){
	if (!o) o= ++top;
	z[i][o]= -1;
	if (l+1==r){
		if (c[Y[l]]==i)
			s[i][o]= 1;
		return;
	}
	int mid= (l+r)>>1;
	build(left[i][o],l,mid,i);
	build(right[i][o],mid,r,i);
	update(o,i);
}
void change(int o,int l,int r,int x,int y,int v,int i){
	if (x<=l&&r<=y){
		z[i][o]= v;
		return;
	}
	pushdown(o,i);
	int mid= (l+r)>>1;
	if (x<mid)
		change(left[i][o],l,mid,x,y,v,i);
	if (mid<y)
		change(right[i][o],mid,r,x,y,v,i);
	update(o,i);
}
int ok(int o,int l,int r,int x,int y,int i){
	if (x<=l&&r<=y){
		if (z[i][o]==-1) return s[i][o];
		return z[i][o];
	}
	pushdown(o,i);
	int mid= (l+r)>>1,re= 0;
	if (x<mid)
		re|= ok(left[i][o],l,mid,x,y,i);
	if (mid<y)
		re|= ok(right[i][o],mid,r,x,y,i);
	update(o,i);
	return re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++) scanf("%d",&c[i]);
	for (i= 1;i<n;i++){
		scanf("%d%d",&x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	L= 1;R= tot+1;
	for (i= 1;i<=60;i++){
		top= 0;
		build(root[i],L,R,i);
	}
	for (int mm= 1;mm<=m;mm++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d%d",&x, &y);
			for (i= 1;i<=60;i++)
				change(root[i],L,R,a[x][0],a[x][1]+1,0,i);
			change(root[y],L,R,a[x][0],a[x][1]+1,1,y);
		}else {
			scanf("%d",&x);
			ans= 0;
			for (i= 1;i<=60;i++)
				ans+= ok(root[i],L,R,a[x][0],a[x][1]+1,i);
			printf("%d\n",ans);
		}
	}return 0;
}
