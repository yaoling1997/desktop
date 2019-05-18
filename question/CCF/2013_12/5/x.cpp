#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
const int maxn= 60,maxm= maxn*maxn;
struct node{
	int x,y;
};
queue<int> Q;
vector<int> g[maxm],G[maxm];
char M[maxn][maxn];
int vis[maxm],vit[maxm];
int R,C,i,j;
void getMove(char c,vector<node> &V){
	V.clear();
	if (c=='S'||c=='T'||c=='+'){
		V.pb((node){-1,0});
		V.pb((node){0,1});
		V.pb((node){1,0});
		V.pb((node){0,-1});		
	}else if (c=='-'){
		V.pb((node){0,-1});
		V.pb((node){0,1});		
	}else if (c=='|'){
		V.pb((node){-1,0});
		V.pb((node){1,0});		
	}else if (c=='.'){
		V.pb((node){1,0});
	}
}
bool out(int x,int y){
	return x<1||x>R||y<1||y>C||M[x][y]=='#';
}
int num(int x,int y){
	return (x-1)*C+y;
}
void bfs(int s,int vis[maxn],vector<int> g[maxn]){
	Q.push(s);
	vis[s]= 1;
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();
		for (i= 0;i<len;i++){
			int v= g[u][i];
			if (vis[v]) continue;
			vis[v]= 1;
			Q.push(v);
		}
	}
}
void solve(){
	int i,j,S,T;
	for (i= 1;i<=R;i++)
		for (j= 1;j<=C;j++){
			if (M[i][j]=='S')
				S= num(i,j);
			if (M[i][j]=='T')
				T= num(i,j);
		}
	bfs(S,vis,g);
	if (!vis[T]){
		printf("I'm stuck!");
		return;
	}
	bfs(T,vit,G);
	int ans= 0;
	for (i= 1;i<=R*C;i++)
		if (vis[i]&&!vit[i])
			ans++;
	printf("%d",ans);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&R, &C);
	for (i= 1;i<=R;i++)
		scanf("%s",M[i]+1);
	for (i= 1;i<=R;i++)
		for (j= 1;j<=C;j++){
			vector<node> V;
			getMove(M[i][j],V);
			int lV= V.size(),k,u= num(i,j);
			for (k= 0;k<lV;k++){
				int xx= i+V[k].x;
				int yy= j+V[k].y;
				if (out(xx,yy)) continue;
				int v= num(xx,yy);				
				g[u].pb(v);
				G[v].pb(u);
			}
		}
	solve();
	return 0;
}
