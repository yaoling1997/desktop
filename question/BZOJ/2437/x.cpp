#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 50,maxl= maxn*maxn;
struct opt{int x,y;};
vector<int> g[maxl];
opt a[maxl];
char s[maxn][maxn];
int B[maxn][maxn],stack[maxl],X[maxl],Y[maxl];
int vis[maxl],d[maxl],D[maxl];
int n,m,i,j,tot,x,y,xb,ob,time,top,now,K;
void getgraph(){
	int i,j;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			if (s[i][j]=='X'||s[i][j]=='.'){
				int u= B[i][j];
				if (s[i-1][j]=='O')
					g[u].push_back(B[i-1][j]);
				if (s[i+1][j]=='O')
					g[u].push_back(B[i+1][j]);
				if (s[i][j-1]=='O')
					g[u].push_back(B[i][j-1]);
				if (s[i][j+1]=='O')
					g[u].push_back(B[i][j+1]);
			}
}
int find(int o){
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (vis[v]!=time){
			vis[v]= time;
			if (!Y[v]&&(!d[v]||find(d[v]))){
				d[v]= o;
				D[o]= v;
				return 1;
			}
		}
	}return 0;
}
bool Find(int o){
	time++;
	return find(o);
}
void solve(){
	int i,k,cnt= 0,bl,u,x;
	for (i= 1;i<=xb;i++)
		if (Find(i)) cnt++;
	for (k= 1;k<=K;k++){
		X[now]= 1;
		if (D[now]==0) bl= 0;
		else {
			D[now]= d[D[now]]= 0;bl= 1;cnt--;
			for (i= 1;i<=xb;i++)
				if (!X[i]&&D[i]==0)
					if (Find(i)){
						cnt++;
						bl= 0;
						break;
					}
		}
		u= B[a[2*k-1].x][a[2*k-1].y];
		Y[u]= 1;		
		if (bl){
			if (d[u]){
				x= d[u];d[u]= 0;D[x]= 0;cnt--;
				if (Find(x)) cnt++;
				else stack[++top]= k;
			}
		}else if (d[u]) D[d[u]]= 0,d[u]= 0,cnt--;
		now= B[a[2*k].x][a[2*k].y];
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%s",s[i]+1);
	scanf("%d",&K);
	for (i= 1;i<=K;i++){
		scanf("%d %d",&x, &y);
		a[2*i-1]= (opt){x,y};
		scanf("%d %d",&x, &y);
		a[2*i]= (opt){x,y};
	}
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			if (s[i][j]=='X') B[i][j]= ++xb;
			else if (s[i][j]=='O') B[i][j]= ++ob;
			else B[i][j]= now= ++xb;
	getgraph();
	solve();
	printf("%d\n",top);
	for (i= 1;i<=top;i++)
		printf("%d\n",stack[i]);
	return 0;
}
