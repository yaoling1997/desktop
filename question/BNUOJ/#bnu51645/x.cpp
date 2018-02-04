#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e3,oo= 1e9;
int X[maxn],Y[maxn];
int b[maxn];
int n,m,i,j,x,y,sh,Max= 10,T;
void dfs(int o,int now){
	if (now>Max)
		return;	
	if (o>m){
		sh= min(sh,now);
		return;
	}
	if (b[X[o]]||b[Y[o]]) dfs(o+1,now);
	else {
		b[X[o]]= 1;
		dfs(o+1,now+1);
		b[X[o]]= 0;
		b[Y[o]]= 1;
		dfs(o+1,now+1);
		b[Y[o]]= 0;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		scanf("%d%d",&n, &m);
		sh= oo;
		for (i= 1;i<=m;i++)
			scanf("%d%d",&X[i], &Y[i]);
		dfs(1,0);
		if (sh>10){
			printf("GG\n");
		}else printf("%d\n",sh);
	}return 0;
}
