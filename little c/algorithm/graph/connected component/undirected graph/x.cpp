#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 3001;
int des[maxn],next[maxn],head[maxn],v[maxn],vis[maxn];
int n,m,i,x,y,top;
void dfs(int o){
	vis[o]= top;
	int p= head[o];
	while (p){
		if (!vis[des[p]])
			dfs(des[p]);
		p= next[p];
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		top++;
		des[top]= y;
		next[top]= head[x];
		head[x]= top;
		top++;
		des[top]= x;
		next[top]= head[y];
		head[y]= top;
	}
	top= 0;
	for (i= 1;i<=n;i++)
		if (!vis[i]){
			top++;
			dfs(i);
		}
	printf("%d\n",top);
	for (i= 1;i<=n;i++)
		printf("%d ",vis[i]);
	return 0;
}
