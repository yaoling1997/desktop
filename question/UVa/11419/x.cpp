#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001;
vector<int> g[maxn];
int d[maxn],vis[maxn],B[maxn],Cx[maxn],Cy[maxn];
int n,i,j,x,y,R,C,time,ans;
void init(){
	memset(d,0,sizeof(d));
	memset(B,0,sizeof(B));
	memset(Cx,0,sizeof(Cx));
	memset(Cy,0,sizeof(Cy));	
	int i;ans= 0;
	for (i= 1;i<=R;i++) g[i].clear();
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
void go(int o){
	Cx[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!Cy[v]){
			Cy[v]= 1;
			go(d[v]);
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d%d%d",&R, &C, &n)>0){
		if (!R) break;
		init();
		for (i= 1;i<=n;i++){
			scanf("%d%d",&x, &y);
			g[x].push_back(y);
		}
		for (i= 1;i<=R;i++){
			time++;
			if (find(i)) B[i]= 1,ans++;
		}
		for (i= 1;i<=R;i++)
			if (!B[i]) go(i);
		printf("%d",ans);
		for (i= 1;i<=R;i++)
			if (!Cx[i])
				printf(" r%d",i);
		for (i= 1;i<=C;i++)
			if (Cy[i])
				printf(" c%d",i);
		printf("\n");
	}return 0;
}
