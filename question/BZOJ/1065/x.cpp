#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 100;
double C[maxn],pow[maxn],F[maxn][maxn],f[maxn][maxn][maxn];
int su[maxn],d[maxn],stack[maxn],b[maxn];
vector<int> g[maxn];
double K,ans;
int n,m,top,i,j,k,x,cnt,M;
void topu(){
	queue<int> Q;
	int i;
	for (i= 1;i<=n;i++)
		if (!d[i]) Q.push(i);
	while (!Q.empty()){
		int u= Q.front();
		Q.pop();
		d[su[u]]--;
		if (!d[su[u]]) Q.push(su[u]);
	}
}
void getgraph(){
	for (i= 2;i<=n;i++)
		g[su[i]].push_back(i);
}
void dfs(int o,int d){
	double &res= f[o][M][d];
	if (res>=0) return;
	int len= g[o].size(),i,j,k;
	if (!len){
		f[o][0][d]= C[o]*pow[d];
		for (i= 1;i<=M;i++)
			if (b[o]) f[o][i][d]=  C[o]*pow[d];
			else f[o][i][d]= C[o]*pow[1];
		return;
	}
	for (i= 0;i<len;i++){
		int v= g[o][i];
		dfs(v,d+1);
		dfs(v,2);		
	}
	for (i= 0;i<=m;i++) F[o][i]= 0;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		for (k= M;k>=0;k--)
			for (j= 0;j<=k;j++)
				F[o][k]= max(F[o][k],F[o][k-j]+f[v][j][d+1]);
	}
	for (i= 0;i<=M;i++)
		f[o][i][d]= F[o][i]+C[o]*pow[d];	
	if (!b[o]&&M){
		for (i= 0;i<=m;i++) F[o][i]= 0;		
		for (i= 0;i<len;i++){
			int v= g[o][i];
			for (k= m-1;k>=0;k--)
				for (j= 0;j<=k;j++)
					F[o][k]= max(F[o][k],F[o][k-j]+f[v][j][2]);
		}for (i= 1;i<=M;i++)
			 f[o][i][d]= max(f[o][i][d],F[o][i-1]+C[o]*pow[1]);
	}	
}
void go(int o,int w){
	int x= su[o];b[o]= w;cnt= 1;
	while (x!=o)
		b[x]= w,x= su[x],cnt++;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %lf",&n, &m, &K);
	pow[0]= 1;	
	for (i= 1;i<=n;i++){
		scanf("%d",&su[i]);
		d[su[i]]++;
		pow[i]= pow[i-1]*K;
	}
	for (i= 1;i<=n;i++) scanf("%lf",&C[i]);
	topu();
	for (i= 2;i<=n;i++)
		if (d[i]) stack[++top]= i;
	if (!m){
		for (i= 0;i<=n;i++)
			for (j= 0;j<=n;j++)
				for (k= 0;k<=n;k++)
					f[i][j][k]= -1;
		getgraph();
		M= 0;
		dfs(1,0);
		go(stack[1],1);
		ans= max(ans,f[1][M][0]/(1-pow[cnt]));
		printf("%.2lf",ans);
		return 0;
	}
	for (int a1= 1;a1<=top;a1++){		
		for (i= 1;i<=n;i++) g[i].clear();
		for (i= 0;i<=n;i++)
			for (j= 0;j<=n;j++)
				for (k= 0;k<=n;k++)
					f[i][j][k]= -1;
		int u= stack[a1];
		x= su[u];
		su[u]= 1;
		go(1,1);
		getgraph();
		M= x==1? m:m-1;
		dfs(1,0);
		ans= max(ans,f[1][M][0]/(1-pow[cnt]));
		go(1,0);
		su[u]= x;
	}printf("%.2lf",ans);
	return 0;
}
