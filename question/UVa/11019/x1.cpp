#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 1010,sig= 26,maxm= 1e5+10;
struct node{
	int ch[sig];
	int v;
	void clear(){
		memset(ch,0,sizeof(ch));
		v= 0;
	}
}a[maxm];
vector<int> V[maxm];
queue<int> Q;
char t[maxn][maxn],p[maxn][maxn];
int C[maxn][maxn];
int f[maxm],last[maxm];
int T,ans,X,Y,now,i,j,top,n,m;
int idx(char c){return c-'a';}
void init(){
	memset(C,0,sizeof(C));
	ans= 0;
	int i;
	for (i= 0;i<=top;i++){
		a[i].clear();
		V[i].clear();
	}
	top= 0;
}
void getFail(){
	f[0]= last[0]= 0;
	int i;
	for (i= 0;i<sig;i++){
		int v= a[0].ch[i];
		if (!v) continue;
		f[v]= last[v]= 0;
		Q.push(v);
	}
	while (!Q.empty()){
		int u= Q.front();
		Q.pop();
		for (i= 0;i<sig;i++){
			int v= a[u].ch[i];
			if (!v) continue;
			int j= f[u];
			while (j&&!a[j].ch[i]) j= f[j];
			j= a[j].ch[i];
			f[v]= j;
			last[v]= a[j].v?j:last[j];
			Q.push(v);
		}
	}
}
void print(int j,int o,int i){
	while (j){
		int len= V[j].size(),k;
		for (k= 0;k<len;k++){
			int v= V[j][k];
			if (o-v+1<1) break;
			C[o-v+1][i-Y+1]++;
		}
		j= last[j];
	}
}
void find(char *t,int o){
	int len= strlen(t+1),i,j= 0;
	for (i= 1;i<=len;i++){
		int c= idx(t[i]);
		while (j&&!a[j].ch[c]) j= f[j];
		j= a[j].ch[c];
		if (a[j].v) print(j,o,i);
		else print(last[j],o,i);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		init();
		scanf("%d%d",&n, &m);
		for (i= 1;i<=n;i++)
			scanf("%s",t[i]+1);
		scanf("%d%d",&X, &Y);
		for (i= 1;i<=X;i++){
			scanf("%s",p[i]+1);
			now= 0;
			for (j= 1;j<=Y;j++){
				int c= idx(p[i][j]);
				if (!a[now].ch[c]) a[now].ch[c]= ++top;
				now= a[now].ch[c];
			}
			a[now].v++;
			V[now].push_back(i);
		}
		getFail();
		for (i= 1;i<=n;i++)
			find(t[i],i);
		for (i= 1;i<=n;i++)
			for (j= 1;j<=m;j++)
				ans+= C[i][j]==X;
		printf("%d\n",ans);
	}return 0;
}
