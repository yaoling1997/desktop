#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 210;
vector<int> g[maxn];
int d[maxn],vis[maxn];
int ans,i,j,time,n,T,x;
void init(){
	int i;
	for (i= 1;i<=n;i++){
		g[i].clear();
		d[i]= 0;
	}ans= 1;
}
bool find(int o){
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (vis[v]!=time){
			vis[v]= time;
			if (!d[v]||find(d[v])){
				d[v]= o;
				return 1;
			}
		}
	}return 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d",&n);
		init();
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++){
				scanf("%d",&x);
				if (x==1)
					g[i].push_back(j);
			}
		for (i= 1;i<=n;i++){
			time++;
			if (!find(i)){
				ans= 0;
				break;
			}
		}
		printf("%s\n",ans?"Yes":"No");
	}return 0;
}
