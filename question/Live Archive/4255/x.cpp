#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 100;
vector<int> g[maxn];
queue<int> Q;
char s[maxn];
int b[maxn],f[maxn],rd[maxn],vis[maxn];
int a[maxn][maxn];
int i,j,n,m,tim,T;
int idx(char c){
	if (c=='+') return 1;
	if (c=='-') return -1;
	if (c=='0') return 0;
	return 1111111;
}
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
void init(){
	int i;
	tim++;
	for (i= 0;i<=n;i++){
		g[i].clear();
		f[i]= i;
	}
}
bool ok(){
	int i;
	for (i= 0;i<=n;i++){
		if (i!=f[i]) continue;
		if (rd[i]) continue;
		Q.push(i);
		b[i]= 10;
		vis[i]= tim;
	}
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size();
		Q.pop();
		for (i= 0;i<len;i++){
			int v= g[u][i];
			rd[v]--;
			if (!rd[v]){
				Q.push(v);
				b[v]= b[u]-1;
				vis[v]= tim;
			}
		}
	}
	for (i= 1;i<=n;i++){
		if (i!=f[i]) continue;
		if (vis[i]!=tim) return 0;
	}return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		scanf("%d",&n);
		scanf("%s",s+1);
		init();
		m= 0;
		for (i= 1;i<=n;i++)
			for (j= i;j<=n;j++){
				m++;
				a[i][j]= idx(s[m]);
				if (a[i][j]==0){
					find(i-1);
					find(j);
					f[f[i-1]]= f[j];
				}
			}
		for (i= 1;i<=n;i++)
			for (j= i;j<=n;j++){
				if (a[i][j]==1){
					find(i-1);
					find(j);
					g[f[j]].push_back(f[i-1]);
					rd[f[i-1]]++;
				}else if (a[i][j]==-1){
					find(i-1);
					find(j);
					g[f[i-1]].push_back(f[j]);
					rd[f[j]]++;
				}
			}
		if (ok()) for (i= 1;i<=n;i++) printf("%d%c",b[f[i]]-b[f[i-1]], i<n?' ':'\n');
		else printf("shit!\n");
	}return 0;
}
