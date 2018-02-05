#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5,maxm= 1600000;
vector<int> g[maxn];
int X[maxn][2],Y[maxn],V[maxn];
int A[maxm],Z[maxm];
char s[10];
int n,i,tot,q;
void dfs(int o){
	X[o][0]= ++tot;
	Y[tot]= o;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		dfs(v);
	}
	X[o][1]= ++tot;
	Y[tot]= o;
}
void pushdown(int o){
	if (Z[o]){
		Z[o]= 0;
		Z[2*o]^= 1;
		Z[2*o+1]^= 1;
	}
}
void update(int o,int l,int r){
	int m= (l+r)>>1;
	int left= Z[2*o]?m-l-A[2*o]:A[2*o];
	int right= Z[2*o+1]?r-m-A[2*o+1]:A[2*o+1];
	A[o]= left+right;
}
void build(int o,int l,int r){
	if (l+1==r){
		A[o]= V[Y[l]];
		return;
	}
	int m= (l+r)>>1;
	build(2*o,l,m);
	build(2*o+1,m,r);
	update(o,l,r);
}
void change(int o,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		Z[o]^= 1;
		return;
	}
	int m= (l+r)>>1;
	pushdown(o);
	if (x<m)
		change(2*o,l,m,x,y);
	if (m<y)
		change(2*o+1,m,r,x,y);
	update(o,l,r);
}
int get(int o,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		return Z[o]?r-l-A[o]:A[o];
	}
	int m= (l+r)>>1;
	pushdown(o);
	int re= 0;
	if (x<m)
		re+= get(2*o,l,m,x,y);
	if (m<y)
		re+= get(2*o+1,m,r,x,y);
	update(o,l,r);
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i= 2;i<=n;i++){
		int x;
		scanf("%d",&x);
		g[x].pb(i);
	}
	for (i= 1;i<=n;i++)
		scanf("%d",&V[i]);
	dfs(1);
	build(1,1,tot+1);
	scanf("%d",&q);
	for (int qq= 1;qq<=q;qq++){
		int x;
		scanf("%s%d",s+1, &x);
		if (s[1]=='g'){
			int ans= get(1,1,tot+1,X[x][0],X[x][1]+1);
			ans/= 2;
			printf("%d\n",ans);
		}else {
			change(1,1,tot+1,X[x][0],X[x][1]+1);
		}
	}
	return 0;
}
