#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#define ll long long
using namespace std;
const int maxn= 1010;
vector<int> g[maxn];
char s[10000];
int ch[maxn][2],vis[maxn];
set<int> H,T;
int n,m,i,j,h,t,p,q,bl,cnt;
void deal(int o,char *s){
	int len= strlen(s+1);
	int x= 0,i;
	for (i= 1;i<=len;i++){
		if (s[i]<'0'||s[i]>'9'){
			if (x) g[o].push_back(x);
			x= 0;
		}else x= x*10+s[i]-'0';
	}
	if (x) g[o].push_back(x);
}
void dfs(int o,int c){
	vis[o]= 1;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!vis[v]){
			ch[o][c]= v;
			ch[v][c^1]= o;
			dfs(v,c);
			break;
		}
	}
}
bool IN(int u,int v){
	int len= g[u].size(),i;
	for (i= 0;i<len;i++)
		if (g[u][i]==v) return 1;
	return 0;
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++){
		fgets(s+1,sizeof(s)-10,stdin);
		deal(i,s);
	}
	dfs(1,0);
	dfs(1,1);
	for (;;){
		for (i= 1;i<=n;i++){
			if (vis[i]&&!ch[i][1]) t= i;
			if (vis[i]&&!ch[i][0]) h= i;
		}		
		if (IN(h,t)){
			ch[t][1]= h;
			ch[h][0]= t;
		}else {
			p= h;
			int lh= g[h].size(),lt= g[t].size();
			H.clear();
			T.clear();
			for (i= 0;i<lh;i++)
				H.insert(g[h][i]);
			for (i= 0;i<lt;i++)
				T.insert(g[t][i]);
			while (ch[p][1]!=t){
				if (T.count(p)&&H.count(ch[p][1])) break;
				p= ch[p][1];
			}
			q= ch[p][1];
			ch[t][1]= p;
			ch[p][1]= t;
			ch[q][0]= h;
			ch[h][0]= q;
			while (h!= t){
				swap(ch[h][0],ch[h][1]);
				h= ch[h][0];
			}
		}
		cnt= 0;
		for (i= 1;i<=n;i++)
			cnt+= vis[i];
		if (cnt==n) break;
		for (i= 1;i<=n;i++)
			if (!vis[i]){
				bl= 0;
				int len= g[i].size();
				for (j= 0;j<len;j++){
					int v= g[i][j];
					if (vis[v]){
						bl= v;
						break;
					}
				}
				if (bl) break;
			}
		if (i>n){
			printf("shit");
			return 0;
		}
		vis[i]= 1;
		ch[i][1]= bl;
		p= ch[bl][0];
		ch[p][1]= 0;
		ch[bl][0]= i;
		dfs(p,1);
		dfs(i,0);
	}
	h= 1;	
	do {
		printf("%d ",h);
		h= ch[h][1];
	}while (h!=1);
	printf("1");
	return 0;
}
