#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn= 600001,mo= 1e9+3;
vector<int> g[maxn];
ull h[maxn],size[maxn];
int a[maxn],vis[maxn],fa[maxn];
int n,i,x,y,ans,cnt;
void addedge(int x,int y){
	g[x].push_back(y);
	g[y].push_back(x);
}
void bfs(){
	queue<int> Q;
	Q.push(1);vis[1]= size[0]= 1;
	while (!Q.empty()){		
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();h[u]= size[fa[u]]*a[u]%mo;
		for (i= 0;i<len;i++){
			int v= g[u][i];
			if (!vis[v]){
				vis[v]= 1;
				size[u]++;
				fa[v]= u;
				Q.push(v);
			}
		}
		size[u]= size[u]*size[fa[u]]%mo;
	}
}
int gi(){
	char c= getchar();int re= 0;
	while (c<'0'||c>'9')c= getchar();
	while (c>='0'&&c<='9')re= re*10+c-'0',c= getchar();
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		a[i]= gi();
	for (i= 1;i<n;i++){
		x= gi();y= gi();
		addedge(x,y);
	}
	bfs();
	ans= n;
	sort(h+1,h+n+1);
	cnt= 1;
	for (i= 2;i<=n;i++)
		if (h[i]==h[i-1]) cnt++;
		else ans= min(ans,n-cnt),cnt= 1;		
	ans= min(ans,n-cnt);
	printf("%d",ans);
	return 0;
}
