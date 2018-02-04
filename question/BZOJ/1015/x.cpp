#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 6e5;
vector<int> g[maxn];
int f[maxn],c[maxn],B[maxn],stack[maxn],b[maxn],S[maxn];
int top,i,j,x,y,cnt,n,m;
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		x++;y++;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	scanf("%d",&x);
	while (scanf("%d",&x)!=EOF){
		x++;
		stack[++top]= x;
		b[x]= 1;
	}
	for (i= 1;i<=n;i++) f[i]= i;
	for (i= 1;i<=n;i++)
		if (!b[i]){
			int len= g[i].size(),j;
			for (j= 0;j<len;j++){
				int v= g[i][j];
				if (b[v]) continue;
				find(i);find(v);
				f[f[i]]= f[v];
			}
		}
	for (i= 1;i<=n;i++){
		if (b[i]) continue;
		find(i);
		if (!B[f[i]]) B[f[i]]= 1,cnt++;
	}
	for (i= top;i>0;i--){
		S[i]= cnt;
		int u= stack[i],len= g[u].size();
		b[u]= 0;cnt++;
		for (j= 0;j<len;j++){
			int v= g[u][j];
			if (b[v]) continue;
			if (find(u)!=find(v)){
				f[f[u]]= f[v];
				cnt--;
			}
		}
	}S[0]= cnt;
	for (i= 0;i<=top;i++)
		printf("%d\n",S[i]);
	return 0;
}
